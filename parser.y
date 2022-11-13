//Asher Shores, Riley Monwai, Even Klever
// CST-405: Compilers
// Professor Isac Artzi

/* %code requires
  {
    #define YYSTYPE double
  } */
%{
//Standard libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Other Files 
#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "MIPScode.h"
#include "funcMIPS.h"

//Bison stuff I assume... IDK what it does
extern int yylex();
extern int yyparse();
extern FILE* yyin;

//Some global variables
int computeEquation(int val1, int val2, char operator);
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
	float floatValue;
	char character;
	char* string;
	struct AST* ast;
}

//Tokes declared in Parser so we can look for them
//%token <string> TYPE
%token <string> ID
%token <string> SEMICOLON
%token <string> EQ
%token <number> INTEGER
%token <floatValue> DECIMAL
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
/* %token <string> APOST */

//TYPES
%token <string> INT
%token <string> CHAR
%token <string> FLOAT

//Keywords??
%token <string> RETURN
%token <string> WRITELN

%token <string> CHARACTER

//Math
%left PLUS
%left MINUS
%left TIMES
%left DIVIDE

//Idk what this does
%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } INTEGER;

//All the program grammar that will come up
%type <ast> Program DeclList Decl VarDeclList FunDeclList VarDecl FunDecl ParamDecList Block ParamDecListTail ParamDecl Type Stmt StmtList ArrayExpr Expr MathExpr Trm Factor ParamList Primary UnaryOp BinOp 

%start Program

%%

Program: 

	DeclList {
		
		$$ = $1;
		printAST($$, 3);

	}
;

DeclList:	
	Decl DeclList { 

		// printf("\nTest debug DECLDECLLIST\n");
		$1->right = $2;
		$$ = $1;
		// printf("LINK DECLLIST\n");
		// printNode($$->right);

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
		if (inSymTab == 0)  {
			addItem($2, "Var", $1->nodeType, currentScope);
			showSymTable();
		}
		else {
			printf("SEMANTIC ERROR: Var %s is already in the symbol table\n", $2);
			semanticCheckPassed = 0;
		}


		// ------  AST  ------ //
		if (semanticCheckPassed) {

			$$ = AST_Type("TYPE", $1->nodeType, $2);


			// ---- CODE GENERATION ---- //
			// code generation occurs when variable 
			// recieves a value to save space
			
		}

		semanticCheckPassed = 1;
	}
	

	// ------ ARRAY DECL ------ //
	| Type ID LBRACKET INTEGER RBRACKET SEMICOLON {
		
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

			showSymTable();
		} else {
			printf("SEMANTIC ERROR: Var %s is already in the symbol table\n", $2);
		}


		// ----- AST ----- //
		char intVal[50]; 
		sprintf(intVal, "%d", $4);
		$$ = AST_assignment("ARR", intVal, $2);


		// ----- CODE GENERATION ----- //
		
		// ---- IR CODE ---- //
		// emitArrayDecl($2, $4);


		// ---- MIPS CODE ---- //
		emitMIPSArrayDecl($2, $4);

		semanticCheckPassed = 1;
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
			
			addItem($3, "FUNC", $2->nodeType, currentScope);
			showSymTable();

		} 
		else {
			printf("SEMANTIC ERROR: Function %s is already in the symbol table\n", $2->nodeType);
			semanticCheckPassed = 0;
		}
	} 

	ParamDecList RPAREN Block {

		// ----- AST ----- //
		if (semanticCheckPassed) {
			$$ = AST_assignment("FUNC", $2->nodeType, $3);		

			printNode($$);

			// ---- CODE GENERATION ---- //

			// ---- IR CODE ---- //


			// ---- MIPS CODE ---- //
			emitMIPSFunc($3);
		}



		semanticCheckPassed = 1;
		
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
		// ---- Symbol Table ---- //
		symTabAccess();

		//Var Decl Check
		int inSymTab = found($2, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);

		if (inSymTab == 0) {
			addItem($2, "Var", $1->nodeType, currentScope);
			showSymTable();
		} 
		else {
			printf("\nSEMANTIC ERROR: Var %s is already in the symbol table\n", $2);
		} 

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
		$$ = AST_assignment("RETURN", "", $2->RHS);
		// printNode($$);		
	}


	| WRITE Expr SEMICOLON {
		printf("\nRECOGNIZED RULE: Write Statement\n");

		// printf("EXpr: %s\n", $2);
		$$ = AST_Write("WRITE", "", $2->nodeType);

		// ------ IRCODE GENERATION ------ //
		emitIRWriteId($2->LHS, getVariableType($2->LHS, currentScope));
		// ------ ¯\_(ツ)_/¯ ------ //

		// ------ CODE GENERATION ------ //
		// printf("Test: %s\n", $2->RHS);
		if (strcmp($2->nodeType,"=") == 0) {

			emitMIPSWriteId($2->LHS, getVariableType($2->LHS, currentScope));

		}
		
	}


	| WRITELN SEMICOLON {
		printf("\nRECOGNIZED RULE: Write Line %s\n", $1);
	}

;


//==========================================

ArrayExpr:

	ID LBRACKET INTEGER RBRACKET EQ Primary {

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
		setItemValue(arrayStmt, $6->RHS, currentScope);


		// ----- AST ----- //
		$$ = AST_assignment("=", arrayStmt, newVal);		


		// ---- CODE GENERATION ---- //

			// ---- IR CODE ---- //


			// ---- MIPS CODE ---- //
		//TODO we only have functionality to add to ints at the moment 
		emitMIPSIntArrayAssign($1, $3, atoi($6->RHS));

	}


	| ID EQ ID LBRACKET INTEGER RBRACKET {

		symTabAccess();
		int inSymTab = found($1, currentScope);

		// Getting array value in the symbol table
		if (inSymTab) {

			char arrayStmt[10]; char newVal[10];
			sprintf(arrayStmt, "%s%s%d%s", $3, $4, $5, $6);

			int arrayVal = getValue(arrayStmt, currentScope);
			sprintf(newVal, "%d", arrayVal);


			// ---- SYMBOL TABLE ---- //
			setItemValue($1, newVal, currentScope);


			// ------ AST ------ //
			$$ = AST_assignment("=", $1, newVal);


			// ---- CODE GENERATION ---- //

			// ---- IR CODE ---- //
			//TODO

			// ---- MIPS CODE ---- //
			
		}

	}

;


Expr: 
	Primary 

	| MathExpr

	| ArrayExpr

	| UnaryOp Expr { 

		//Asher's Semantic Checls
		// ------- SYMBOL TABLE ------- //
		symTabAccess();
		int inSymTab = found($2->RHS, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab == 0) {
			printf("\nSEMANTIC ERROR: Expr %s is NOT in the symbol table\n", $2->nodeType);
		}
		showSymTable();

		//TODO fix negative numbers :)
		// $$ = $2;

	}

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

		// printNode($3);
		if (strcmp(getVariableType($1, currentScope), $3->nodeType) == 0) {
			printf("TYPES ARE COMPATIBLE\n");
		} else {
			printf("Error: INCOMPATIBLE TYPES\n");
			semanticCheckPassed = 0;
		}


		// ------- SYMBOL TABLE ------- //
		if (semanticCheckPassed) {
			printNode($3);
			setItemValue($1, $3->RHS, currentScope);
		}
		

		// ------ AST ------ //
		$$ = AST_assignment("=", $1, $3->RHS);
		// printNode($$);


		// ------ CODE GENERATION ------ //

		if (semanticCheckPassed) {

			char *test = getVariableType($1, currentScope);

 			//¯\_(ツ)_/¯ ¯\_(ツ)_/¯ ¯\_(ツ)_/¯

			// ---- CODE GENERATION ---- //

				// ---- CHAR CODE ---- // 
			if (strcmp(test, "char") == 0) {

				// ---- IR CODE ---- // 
				emitIRCharDecl($1, $3->RHS);
				
				// ---- MIPS CODE ---- // 
				emitMIPSCharDecl($1, $3->RHS);

			}

				// ---- INT CODE ---- // 
			else if (strcmp(test, "int") == 0) {

				// ---- IR CODE ---- //
				emitIntVarIR($1, atoi($3->RHS));

				// ---- MIPS CODE ---- //
				emitIntVar($1, atoi($3->RHS));
			}

		}

		semanticCheckPassed = 1;
	}

	| ID LPAREN ParamList RPAREN {printf("\nRECOGNIZED RULE: Function Call %s\n", $1);}


;

MathExpr: 
	Trm	
	
	| MathExpr MINUS Trm {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", $2);

		sprintf(newVal, "%d", computeEquation(atoi($1->RHS), atoi($3->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		$$ = AST_assignment("int", "", newVal);

	}

	| MathExpr PLUS Trm {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", $2);

		sprintf(newVal, "%d", computeEquation(atoi($1->RHS), atoi($3->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		$$ = AST_assignment("int", "", newVal);

	}

;

Trm: 
	Factor {
		char numVal[10];
		if (strcmp($1->nodeType,"id") == 0) {
			// printf("ID Found!\n");
			sprintf(numVal, "%d", getValue($1->RHS, currentScope));
			$$ = AST_assignment("=", $1->RHS, numVal);

			// Set item to used 
			setItemUsed($1->RHS, currentScope);

		} else {
			//primary is a number, do nothing
			$$ = $1;
		}
	}	

	| Trm TIMES Factor {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", $2);

		sprintf(newVal, "%d", computeEquation(atoi($1->RHS), atoi($3->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		$$ = AST_assignment("int", "", newVal);

	}

	| Trm DIVIDE Factor {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", $2);

		sprintf(newVal, "%d", computeEquation(atoi($1->RHS), atoi($3->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		$$ = AST_assignment("int", "", newVal);

	}
;

Factor:
	ID {
		$$ = AST_assignment("id", "" , $1);
	}

	| INTEGER {
		// printf("int detected\n");
		char numVal[10];
		sprintf(numVal, "%d", $1);
		$$ = AST_assignment("int", "", numVal);
	}

	| LPAREN MathExpr RPAREN {
		$$ = AST_assignment("int", "", $2->RHS);
	}


ParamList:	{}
	| Primary {printf("\nRECOGNIZED RULE: Parameter\n");} ParamList {}
;


//==========================================

Primary: 
	ID {
		$$ = AST_assignment("id", "" , $1);
	}

	| DECIMAL {
		printf("float detected: %f\n", $1);
		char numVal[10];
		sprintf(numVal, "%f", $1);
		$$ = AST_assignment("float", "", numVal);
	}
	
	| INTEGER {
		// printf("int detected\n");
		char numVal[10];
		sprintf(numVal, "%d", $1);
		$$ = AST_assignment("int", "", numVal);
	}

	|  CHARACTER  {

		$$ = AST_assignment("char", "", $1);

	}
	/* | LPAREN Expr RPAREN  */

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

	emitEndOfAssemblyCode();
	emitEndOfAssemblyCodeIR();

	// Merge data and main sections in MIPS
	addMainToData();
	addMainToDataIR();
	showSymTable();
	printf("\n\n##### COMPILER ENDED #####\n\n");


	/* fprintf (GarbageMIPS, "syscall\n"); */
}

int computeEquation(int val1, int val2, char operator) {

	/* char newVal[3]; */
	int newVal;
	/* printf("Equation detected: %d %c %d", val1, operator, val2); */

	switch (operator) {
		case '+':
			newVal = val1 + val2;
			/* sprintf(newVal, "%d", val1 + val2); */
			printf("Addtion Expr found!\n");
			break;
		case '-':
			newVal = val1 - val2;
			/* sprintf(newVal, "%d", val1 - val2); */
			printf("Subtraction Expr found!\n");
			break;
		case '*':
			newVal = val1 * val2;
			/* sprintf(newVal, "%d", val1 * val2); */
			printf("Multiplication Expr found!\n");
			break;
		case '/':
			newVal = val1 / val2;
			/* sprintf(newVal, "%d", val1 / val2); */
			printf("Division Expr found!\n");
			break;
	}

	/* printf("Newval = %d\n", newVal); */
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