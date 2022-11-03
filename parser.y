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

//Bison stuff I assume... IDK what it does
extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;
FILE * GarbageMIPS;

//Some global variables
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
%token <string> PLUS
%token <number> NUMBER
%token <string> WRITE
%token <string> FUNC

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

//Idk what this does
%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;

//All the program grammar that will come up
%type <ast> Program VarDeclList FunDeclList VarDecl ArrDecl FunDecl FuncRun ParamDecList Block ParamDecListTail ParamDecl Type Stmt StmtList Expr ParamList Primary UnaryOp BinOp

%start Program

%%

// Program ------> VarDeclList FunDeclList 
Program: 
	VarDeclList FunDeclList {

		printf("Program started:\n");

		// ------ AST ------ //
		// struct AST* rightMost = getEndNode($1);
		// rightMost->right = $2; 

		printf("LAST DECLARED VAR = %s | RHS = %s\n", lastVar->nodeType, lastVar->RHS);
		lastVar->right = $2;
		$$ = $1;
		
		printAST($$, 3);
	}
;

//==========================================

//VarDeclList --> epsilon 
//                VarDecl VarDeclList
VarDeclList: /* EPSILON */ { /*printf("\nNo VarDeclList (EPSILON)\n");*/}

	|	VarDecl VarDeclList	{
		$1->right = $2;
		$$ = $1;
	}

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
			addItem($2, "Var", $1, currentScope);
		else
			printf("SEMANTIC ERROR: Var %s is already in the symbol table\n", $2);

		showSymTable();


		// ------  AST  ------ //
		$$ = AST_Type("TYPE", $1, $2);
		lastVar = $$;
		//printf("--------> Node:%s, %s\n", $$->nodeType, $$->RHS);

	}
		/* | Type ID LBRACKET NUMBER RBRACKET SEMICOLON {printf("\nRECOGNIZED RULE: ARRAY declaration %s\n\n", $2);
		} */
	| ArrDecl
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
// For reference --> void addItem(char itemName[50], char itemKind[8], char itemType[8], int arrayLength, char scope[50])

//FunDecl ------> Type id ( ParamDecList ) Block
FunDecl:
	FUNC Type ID LPAREN ParamDecList RPAREN Block {

		printf("\nRECOGNIZED RULE: FUNCTION declaration %s\n\n", $3);


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


		// ----- AST ----- //
		$$ = AST_assignment("FUNC", $2, $3);		

		strcpy(currentScope, $3);

		// printf("CurrentScope = %s\n", currentScope);
	}
;

FuncRun: LPAREN ParamDecList RPAREN Block {
			printf("\nRECOGNIZED RULE: FUNCTION declaration %s\n\n", currentScope);
			//Asher's Semantic Checks
			//Symbol Table
			symTabAccess();
			int inSymTab = found(currentScope, currentScope);
			//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
			if (inSymTab == 0) {
				addItem(currentScope, "FUNC", "Func", 0, "GLOBAL");
			} else {
				printf("\nSEMANTIC ERROR: FUNC %s is already in the symbol table\n", $2);
			} 
			showSymTable();
			strcpy(currentScope, "GLOBAL");
	}

;	

ArrDecl:
	Type ID LBRACKET NUMBER RBRACKET SEMICOLON {

		printf("ARRAY DECL FOUND ----> \n");
		// ----- SYMBOL TABLE ----- //
		symTabAccess();

		int inSymTab = found($2, currentScope);

		if (inSymTab == 0) {
			char arrIndex[12];
			for (int i = 0; i < $4; i++) {
				snprintf(arrIndex, 12, "%s[%d]", $2, i);
				addItem(arrIndex, "ARRAY", $1, currentScope);				
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


		// ----- CODE GENERATION ----- //
		// emitArrayDecl($2, $4, getItemID($2, currentScope));

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
	LCURLY VarDeclList StmtList RCURLY {
		// $2->right = $3;
		// $$ = $1;
	}
;

//=================f=========================

//Type ---------> int
//                char
//                float
Type: INT {}
	| FLOAT {}
	| CHAR {}

//==========================================

//StmtList -----> Stmt 
//                Stmt StmtList 
StmtList: Stmt {}
	| Stmt StmtList {}
;

//==========================================

//Stmt ---------> ;
//                Expr ; 
//                return Expr ;
//                read id ;
//                write Expr ;
//                writeln ;
Stmt: 
	SEMICOLON {
		printf("\nRECOGNIZED RULE: SEMICOLON %s\n", $1);	
	}

	| Expr SEMICOLON {}

	| RETURN Expr SEMICOLON {}

	| WRITE Expr SEMICOLON {
		printf("\nRECOGNIZED RULE: Write Statement\n");
	}

	| WRITELN SEMICOLON {
		printf("\nRECOGNIZED RULE: Write Line %s\n", $1);
	}

	| RETURN Expr SEMICOLON
;

//==========================================

Expr: 
	Primary {}

	| UnaryOp Expr { //Asher's Semantic Checls
					//Symbol Table
		symTabAccess();
		int inSymTab = found($2, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab == 0) {
			printf("\nSEMANTIC ERROR: Expr %s is NOT in the symbol table\n", $2->nodeType);
		}
		showSymTable();
	}

	| Expr BinOp Expr {}


	| ID EQ Expr {
		printf("\nRECOGNIZED RULE: Assignment Statement %s\n", $1);
	
		//Asher's Semantic Checks
		//Symbol Table
		symTabAccess();
		//Var Decl Check
		int inSymTab = found($1, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab != 0) {
			printf("\nSEMANTIC ERROR: Var %s is NOT in the symbol table\n", $2);
		} else {
			printf("\nSEMANTIC PASSED");
		}
		showSymTable();	
	}

	| ID LPAREN ParamList RPAREN {printf("\nRECOGNIZED RULE: Function Call %s\n", $1);}
	
	
	| ID LBRACKET Expr RBRACKET EQ Expr {

		printf("\nRECOGNIZED RULE: ARRAY assignment %s\n", $1);
		//Asher's Semantic Checks
		//Symbol Table
		symTabAccess();
		//Var Decl Check
		int inSymTab = found($1, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab != 0) {
			printf("\nSEMANTIC ERROR: ARR %s is NOT in the symbol table\n", $2);
		} else {
			printf("\nSEMANTIC PASSED");
		}
		showSymTable();	
	}
;

ParamList:	{}
	| Primary {printf("\nRECOGNIZED RULE: Parameter\n");} ParamList {}
;


//==========================================

Primary: ID {}
		| NUMBER {}
		| CHARACTER {}
		| LPAREN Expr RPAREN {}

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

	// Initialize currentScope = "GLOBAL"

	/* IRcode = fopen("IRcode.ir", "w");
	printf("IR File Opened");
	GarbageMIPS = fopen("GarbageMIPS.asm", "w");
	printf("MIPS File Opened");

	//print basic MIPS crap into the file
	fprintf (GarbageMIPS, ".text\n");
	fprintf (GarbageMIPS, "main:\n");

	//fprintf(MIPS, " .text"); */
	
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