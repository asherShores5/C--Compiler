//Asher Shores
// CST-405: Compilers
// Professor Isac Artzi

%{
//Standard libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Other Files 
// Need tp add IR + MIPS Code??
#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "MIPScode.h"
#include "Calculator.h"

//Bison stuff I assume... IDK what it does
extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;
FILE * GarbageMIPS;

//Some global variables
const char* computeEquation(int val1, int val2, char operator);
void yyerror(const char* s);
char currentScope[50] = "GLOBAL"; // global or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks
char typeTemp[50];
struct AST * lastVar; 

int count = 0;

%}

%union {
	//Tokens declared in C so we can declare them in C--... I think
	int number;
	char character;
	char* string;
	struct AST* ast;
}

//Tokes declared in Parser so we can look for them
//%token <string> TYPE
%token <string> ID
%token <string> SEMICOLON
%token <string> EQ
%token <number> NUMBER
%token <string> WRITE
%token <string> FUNC

%token <string> PLUS
%token <string> MINUS
%token <string> TIMES
%token <string> DIVIDE

%token <string> LBRACKET
%token <string> RBRACKET
%token <string> LPAREN
%token <string> RPAREN
%token <string> LCURLY
%token <string> RCURLY

%token <string> INT
%token <string> CHAR
%token <string> FLOAT

%token <string> RETURN
%token <string> WRITELN

%token <string> CHARACTER

%left TIMES
%left DIVIDE
/* %left '-'
%left '+' */

//Idk what this does
%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;

//All the program grammar that will come up
%type <ast> Program DeclList Decl VarDeclList FunDeclList VarDecl FunDecl ParamDecList Block ParamDecListTail ParamDecl Type Stmt StmtList Expr MathExpr ParamList Primary UnaryOp BinOp 

%start Program

%%

// Program ------> VarDeclList FunDeclList 
Program: 
	/* VarDeclList FunDeclList {

		printf("Program started:\n");

		// ------ AST ------ //
		// struct AST* rightMost = getEndNode($1);
		// rightMost->right = $2; 

		// printf("LAST DECLARED VAR = %s | RHS = %s\n", lastVar->nodeType, lastVar->RHS);
		lastVar->right = $2;
		$$ = $1;
		printf("$$ right: %s", $1->right);
		
		printAST($$, 3);
	} */

	DeclList {
		
		$$ = $1;
		// printAST($$, 3);

	}
;

DeclList:	
	Decl DeclList { 

		// printf("\nTest debug DECLDECLLIST\n");
		$1->right = $2;
		$$ = $1;
		// printf("LINK DECLLIST\n");
		// printNode($$->right);
	
	// } | StmtList DeclList  { 

	// 	// printf("Test debug STMTDECLLIST\n");
	// 	$1->right = $2;
	// 	$$ = $1;

	} 

	| Decl {
		$$ = $1;
		// printf("DECL\n");
	}
	
	| FunDeclList

;

//==========================================

//VarDeclList --> epsilon 
//                VarDecl VarDeclList
VarDeclList: /* EPSILON */ { /*printf("\nNo VarDeclList (EPSILON)\n");*/}

	|	VarDecl VarDeclList	{
		$1->right = $2;
		$$ = $1;
	}

	| VarDecl 

;


Decl: 		
	VarDecl 
	| StmtList
	| FunDecl
	
;

//==========================================

//VarDecl ------> Type id ;
//               Type id [num] ; // array fdecl
VarDecl: 
	Type ID SEMICOLON {

		printf("\nRECOGNIZED RULE: VARIABLE declaration %s\n\n", $2);


		// ----- SYMBOL TABLE ----- //
		symTabAccess();
		int inSymTab = found($2, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		

		// ------ SEMANTIC CHECKS ------ //
		if (inSymTab == 0) 
			addItem($2, "Var", $1->nodeType, currentScope);
		else
			printf("SEMANTIC ERROR: Var %s is already in the symbol table\n", $2);

		showSymTable();


		// ------  AST  ------ //
		$$ = AST_Type("TYPE", $1->nodeType, $2);
		lastVar = $$;
		//printf("--------> Node:%s, %s\n", $$->nodeType, $$->RHS);

	}
	

	// ------ ARRAY DECL ------ //
	| Type ID LBRACKET NUMBER RBRACKET SEMICOLON {
		
		printf("\nRECOGNIZED RULE: ARRAY declaration %s\n\n", $2);

		// ----- SYMBOL TABLE ----- //
		symTabAccess();

		int inSymTab = found($2, currentScope);

		if (inSymTab == 0) {
			char arrIndex[12];
			for (int i = 0; i < $4; i++) {
				sprintf(arrIndex, "%s[%d]", $2, i);
				addItem(arrIndex, "ARRAY", $1->nodeType, currentScope);				
			}
			// addItem($2, "ARRAY", $1, $4, currentScope);
			showSymTable();
		} else {
			printf("SEMANTIC ERROR: Var %s is already in the symbol table\n", $2);
		}


		// ----- AST ----- //
		char intVal[50]; 
		sprintf(intVal, "%d", $4);
		$$ = AST_assignment("ARR", intVal, $2);

		lastVar = $$;


// 		// ----- CODE GENERATION ----- //
// 		// emitArrayDecl($2, $4, getItemID($2, currentScope));
		} 
	// | ArrDecl
;

//==========================================

//FunDeclList --> FunDecl 
//                FunDecl FunDeclList
FunDeclList: 
	FunDecl 

	| FunDecl FunDeclList {
		
		//TODO AST stuff idk what to do about this yet

	}
;

//=========================================

//FunDecl ------> Type id ( ParamDecList ) Block
FunDecl:
	FUNC Type ID LPAREN {
		printf("\nRECOGNIZED RULE: FUNCTION declaration %s\n\n", $3);
		printf("ID = %s\n", $3);
		strcpy(currentScope, $3);
		printf("\n------------------- Scope Change --> ");
		printf("%s", currentScope);
		printf(" -------------------\n");


		// ----- SYMBOL TABLE ----- //
		symTabAccess();
		int inSymTab = found($3, currentScope);

		// ------ SEMANTIC CHECKS ------ //
 		if (inSymTab == 0) {
			
			addItem($3, "FUNC", $2, currentScope);
			showSymTable();
		} else {
			printf("SEMANTIC ERROR: Function %s is already in the symbol table\n", $2);
		}
	} 

	ParamDecList RPAREN Block {

		// ----- AST ----- //
		$$ = AST_assignment("FUNC", $2, $3);		
		

		// printf("TEST %s\n", $6);
		$$ -> right = $6;
	}
;


//==========================================


//ParamDeclList --> epsilon 
//                  ParamDeclListTail
ParamDecList: /* EPSILON */ {printf("No ParamDeclList (EPSILON)\n\n");}

	| ParamDecListTail {}

;

//==========================================

//ParamDeclListTail --> ParamDecl 
//                      ParamDecl, ParamDeclListTail 
ParamDecListTail: 
	ParamDecl {}

	| ParamDecl ParamDecListTail {$1->right = $2; $$ = $1;}

;

//==========================================

//ParamDecl ----> Type id
//                Type id[]
ParamDecl: 
	Type ID {
		printf("\nRECOGNIZED RULE: Parameter VARIABLE declaration %s\n", $2);
		//Asher's Semantic Checks
		//Symbol Table
		symTabAccess();
		//Var Decl Check
		int inSymTab = found($2, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab == 0) {
			addItem($2, "Var", $1, currentScope);
		} else {
			printf("\nSEMANTIC ERROR: Var %s is already in the symbol table\n", $2);
		} 
		showSymTable();
	}

	/* | Type ID LBRACKET RBRACKET {
		printf("\n RECOGNIZED RULE: Parameter ARRAY declaration %s\n", $2);
		//Asher's Semantic Checks
		//Symbol Table
		symTabAccess();
		int inSymTab = found($2, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab == 0) {
			addItem($2, "ARRAY", $1, $4, currentScope);
		} else {
			printf("\nSEMANTIC ERROR: ARR %s is already in the symbol table\n", $2);
		} 
		showSymTable();
	} */
;

//==========================================

//Block --------> { VarDeclList StmtList } 
Block: 
	LCURLY DeclList RCURLY {
		$$ = $2;
		// printf("right: %s\n", $$->right->RHS);
	}
;

//=================f=========================

Type: INT {}
	| FLOAT {}
	| CHAR {}

//==========================================

StmtList: 
	Stmt 

	| Stmt StmtList {
		$1->right = $2;
		$$ = $1;
		// printNode($$);
	}
;

//==========================================

Stmt: 
	SEMICOLON {
		printf("\nRECOGNIZED RULE: SEMICOLON %s\n", $1);	
	}

	| Expr SEMICOLON {}

	| RETURN Expr SEMICOLON {		
		$$ = AST_assignment("RETURN", "", $2);
		// printNode($$);
		
	}

	| WRITE Expr SEMICOLON {
		printf("\nRECOGNIZED RULE: Write Statement\n");

		// printf("EXpr: %s\n", $2);
		$$ = AST_Write("WRITE", "", $2);
		

		// ------ CODE GENERATION ------ //
		// emitMIPSWrite
	}

	| WRITELN SEMICOLON {
		printf("\nRECOGNIZED RULE: Write Line %s\n", $1);
	}

;


//==========================================


Expr: 
	Primary  

	| UnaryOp Expr { 

		//Asher's Semantic Checls
		// ------- SYMBOL TABLE ------- //
		symTabAccess();
		int inSymTab = found($2, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab == 0) {
			printf("\nSEMANTIC ERROR: Expr %s is NOT in the symbol table\n", $2->nodeType);
		}
		showSymTable();

		$$ = $2;

	}


	/* | ID EQ MathExpr {
		printf("\nRECOGNIZED RULE: Assignment Statement %s\n", $1);
	
		//Asher's Semantic Checks
		// ------- SYMBOL TABLE ------- //
		symTabAccess();
		//Var Decl Check
		int inSymTab = found($1, currentScope);
		int mathVal = atoi($3);


		// ------ SEMANTIC CHECKS ------ //
		if (inSymTab == 0) {
			printf("\nSEMANTIC ERROR: Var %s is NOT in the symbol table\n", $2);
			semanticCheckPassed = 0;
		} else {
			printf("\nITEM IS IN SYMTABLE\n");
		}

		if (strcmp(getVariableType($1, currentScope), "int") == 0) {
			printf("TYPES ARE COMPATIBLE\n");
		} else {
			printf("Error: INCOMPATIBLE TYPES\n");
			semanticCheckPassed = 0;
		}

		// ------- SYMBOL TABLE ------- //
		if (semanticCheckPassed) {
			setItemValue($1, $3, currentScope);
		}
		

		// ------ AST ------ //
		$$ = AST_assignment("=", $1, $3);
		printNode($$);


		// ------ CODE GENERATION ------ //
		// IR CODE ATTEMPT DONT KYS - evan Yes kms - Asher no dont kys - evan
		// emitAssignment($1, $3);


		semanticCheckPassed = 1;
	} */

	| ID EQ Expr {
		printf("\nRECOGNIZED RULE: Assignment Statement ----> %s\n", $1);
		int inSymTab = found($1, currentScope);
	

		// ------ SEMANTIC CHECKS ------ //
		if (inSymTab == 0) {
			printf("\nSEMANTIC ERROR: Var %s is NOT in the symbol table\n", $2);
			semanticCheckPassed = 0;
		} else {
			printf("\nITEM IS IN SYMTABLE\n");
		}

		printNode($3);
		if (strcmp(getVariableType($1, currentScope), $3) == 0) {
			printf("TYPES ARE COMPATIBLE\n");
		} else {
			printf("Error: INCOMPATIBLE TYPES\n");
			semanticCheckPassed = 0;
		}


		// ------- SYMBOL TABLE ------- //
		if (semanticCheckPassed) {
			setItemValue($1, $3->RHS, currentScope);
		}
		

		// ------ AST ------ //
		$$ = AST_assignment("=", $1, $3->RHS);
		// printNode($$);


		// ------ CODE GENERATION ------ //

		semanticCheckPassed = 1;
	}

	| ID LPAREN ParamList RPAREN {printf("\nRECOGNIZED RULE: Function Call %s\n", $1);}
	
	
	| ID LBRACKET NUMBER RBRACKET EQ Primary {

		printf("\nRECOGNIZED RULE: ARRAY assignment %s\n", $1);

		//Asher's Semantic Checks
		symTabAccess();
		int inSymTab = found($1, currentScope);

		if (inSymTab != 0) {
			printf("\nSEMANTIC ERROR: ARR %s is NOT in the symbol table\n", $2);
			semanticCheckPassed = 0;
		} else {
			printf("\nSEMANTIC CHECK PASSED\n");
			
			//emitArrayAssignment();
		}
		// ------ SYMBOL TABLE ------ //

		// Setting array value in the symbol table
		char arrayStmt[10]; char newVal[10];
		sprintf(arrayStmt, "%s%s%d%s", $1, $2, $3, $4);
		// printf("setVal %s\n", $6);
		// sprintf(newVal, "%d", $6);
		setItemValue(arrayStmt, $6, currentScope);


		// ----- AST ----- //
		$$ = AST_assignment("=", arrayStmt, newVal);		

	}

	| MathExpr
;

MathExpr:
	ID BinOp MathExpr {
		
		int idValue = getValue($1, currentScope);
		printf("idValue = %d\n", idValue);
		// printf("$2 = %c\n", '+');
		// addNumToArray(idValue, $2);


		// -------- SEMANTIC CHECK -------- //
		// printf("ID is an int! rv = %s", getNodeType($1, currentScope));
		if (strcmp(getVariableType($1, currentScope), "int") != 0) {
			semanticCheckPassed = 0;
		}

	}

	| NUMBER BinOp MathExpr {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", $2);
		char operator = opArray[0];

		strcpy(newVal, computeEquation($1, atoi($3->RHS), operator));
		printf("newVal = %s\n", newVal);

		$$ = AST_assignment("int", "", newVal);
	

		// switch (operator) {
		// 	case '+':
		// 		sprintf(newVal, "%d", $1 + atoi($3->RHS));
		// 		printf("Addtion Expr found!\n");
		// 		break;
		// 	case '-':
		// 		sprintf(newVal, "%d", $1 - atoi($3->RHS));
		// 		printf("Subtraction Expr found!\n");
		// 		break;
		// 	case '*':
		// 		sprintf(newVal, "%d", $1 * atoi($3->RHS));
		// 		printf("Multiplication Expr found!\n");
		// 		break;
		// 	case '/':
		// 		sprintf(newVal, "%d", $1 / atoi($3->RHS));
		// 		printf("Division Expr found!\n");
		// 		break;
		// }


		// printf("$3 = %s\n", $3->RHS);
	}

	| ID {

		char* noOp;
		//Get value of ID from symbol table
		int idValue = getValue($1, currentScope);
		// addNumToArray(idValue, noOp);

		// -------- SEMANTIC CHECK -------- //
		//printf("ID is an int! rv = %s", getNodeType($1, currentScope));

		if (strcmp(getVariableType($1, currentScope), "int") != 0) {
			semanticCheckPassed = 0;
		}

	}

	| NUMBER {
		// printf("Number in mathExpr detected\n");
		char val[5];
		sprintf(val, "%d", $1);
		$$ = AST_assignment("int", "", val);
		// char* noOp;
		// // printf("Number recog\n");
		// addNumToArray($1, noOp);
	}

;
ParamList:	{}
	| Primary {printf("\nRECOGNIZED RULE: Parameter\n");} ParamList {}
;


//==========================================

Primary: ID 
		| NUMBER {
			printf("num detected\n");
			char numVal[10];
			sprintf(numVal, "%d", $1);
			$$ = AST_assignment("int", "", numVal);
		}
		| CHARACTER 
		| LPAREN Expr RPAREN 

UnaryOp: MINUS {printf("\nRECOGNIZED RULE: Unary Operation, NEGATIVE VALUE %s\n", $1);}


BinOp: PLUS {}
    | MINUS {}
	| TIMES {}
	| DIVIDE {}

%%

int main(int argc, char**argv)
{
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");

	// Initialize IR File
	initIRcodeFile();
	// Initialize MIPS.h
	initAssemblyFile();
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}
	yyparse();

	printf("\n\n##### COMPILER ENDED #####\n\n");


	/* fprintf (GarbageMIPS, "syscall\n"); */
}

const char* computeEquation(int val1, int val2, char operator) {

	char newVal[3];

	switch (operator) {
		case '+':
			/* newVal = val1 + val2; */
			sprintf(newVal, "%d", val1 + val2);
			printf("Addtion Expr found!\n");
			break;
		case '-':
			/* newVal = val1 - val2; */
			sprintf(newVal, "%d", val1 - val2);
			printf("Subtraction Expr found!\n");
			break;
		case '*':
			/* newVal = val1 * val2; */
			sprintf(newVal, "%d", val1 * val2);
			printf("Multiplication Expr found!\n");
			break;
		case '/':
			/* newVal = val1 / val2; */
			sprintf(newVal, "%d", val1 / val2);
			printf("Division Expr found!\n");
			break;
	}

	printf("Newval = %s\n", newVal);
	return newVal;

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}

/* Expr: ID EQ ID {
    // perform semantic checks for declarations and types
    if (semantic check passed){
        fprintf (IRcode, " T1 = T2");

        // print assembly

        fprintf(MIPScode, " mov, $r1, $2")
    }
}

...

int main(){

...
IRcode = fopen("IRcode.ir", "w");
...

} */