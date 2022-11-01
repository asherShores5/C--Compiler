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
char currentScope[50]; // global or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks

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
%type <ast> Program VarDeclList FunDeclList VarDecl FunDecl ParamDecList Block ParamDecListTail ParamDecl Type Stmt StmtList Expr ParamList Primary UnaryOp BinOp

%start Program

%%

// Program ------> VarDeclList FunDeclList 
Program: VarDeclList FunDeclList {}
;

//==========================================

//VarDeclList --> epsilon 
//                VarDecl VarDeclList
VarDeclList: /* EPSILON */ { /*printf("\nNo VarDeclList (EPSILON)\n"); */}
		|	VarDecl VarDeclList	{}
;

//==========================================

//VarDecl ------> Type id ;
//               Type id [num] ; // array fdecl
VarDecl: Type ID SEMICOLON {printf("\nRECOGNIZED RULE: VARIABLE declaration %s\n\n", $2);}
		| Type ID LBRACKET NUMBER RBRACKET SEMICOLON {printf("\nRECOGNIZED RULE: ARRAY declaration %s\n\n", $2);
		}
;

//==========================================

//FunDeclList --> FunDecl 
//                FunDecl FunDeclList
FunDeclList: FunDecl {$$ = $1;}
			| FunDecl FunDeclList {$$ = $1;}
;

//==========================================

//FunDecl ------> Type id ( ParamDecList ) Block
FunDecl: FUNC Type ID LPAREN ParamDecList RPAREN Block {
			printf("\nRECOGNIZED RULE: FUNCTION declaration %s\n\n", $3);
			// currentScope = $3
	}

;
//==========================================

//ParamDeclList --> epsilon 
//                  ParamDeclListTail
ParamDecList: /* EPSILON */ {printf("No ParamDeclList (EPSILON)\n");}
			| ParamDecListTail {}
;

//==========================================

//ParamDeclListTail --> ParamDecl 
//                      ParamDecl, ParamDeclListTail 
ParamDecListTail: ParamDecl {}
				| ParamDecl ParamDecListTail {}
;

//==========================================

//ParamDecl ----> Type id
//                Type id[]
ParamDecl: Type ID {printf("\nRECOGNIZED RULE: Parameter VARIABLE declaration %s\n", $2);}
		 | Type ID LBRACKET RBRACKET {printf("\n RECOGNIZED RULE: Parameter ARRAY declaration %s\n", $2);}
;

//==========================================

//Block --------> { VarDeclList StmtList } 
Block: LCURLY VarDeclList StmtList RCURLY {}
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
Stmt: SEMICOLON {printf("\nRECOGNIZED RULE: SEMICOLON %s\n", $1);}
	| Expr SEMICOLON {}
	| RETURN Expr SEMICOLON {}
	| WRITE Expr SEMICOLON {printf("\nRECOGNIZED RULE: Write Statement\n");}
	| WRITELN SEMICOLON {printf("\nRECOGNIZED RULE: Write Line %s\n", $1);}
	| RETURN Expr SEMICOLON
;

//==========================================

Expr: Primary {} 
	| UnaryOp Expr {}
	| Expr BinOp Expr {}
	| ID EQ Expr {printf("\nRECOGNIZED RULE: Assignment Statement %s\n", $1);}
	| ID LPAREN ParamList RPAREN {printf("\nRECOGNIZED RULE: Function Call %s\n", $1);}
	| ID LBRACKET Expr RBRACKET EQ Expr {printf("\nRECOGNIZED RULE: ARRAY assignment %s\n", $1);}
;

ParamList:	{}
	| Primary {printf("\nRECOGNIZED RULE: Parameter %s\n", $1);} ParamList {}
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