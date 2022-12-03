#include <stdio.h>

// Set of functions to emit MIPS code
FILE * mainMIPS;
FILE * dataMIPS;
FILE * funcs;

int inFunc = 0;

void  initAssemblyFile(){
    // Creates a MIPS file with a generic header that needs to be in every file

    mainMIPS = fopen("MIPScode.asm", "w");
    dataMIPS = fopen("dataMIPS.asm", "w");
    funcs = fopen("funcs.asm", "w");
    
    fprintf(mainMIPS, ".text\n");
    fprintf(mainMIPS, "main:\n");
    fprintf(mainMIPS, "# -----------------------\n");

    // data
    fprintf(dataMIPS, ".data\n");
    fprintf(dataMIPS, "newLine: .asciiz \"\\n\"\n");

    fclose(mainMIPS);
    fclose(dataMIPS);
    fclose(funcs);

}

void emitMIPSAssignment(char * id1, char * id2){
    mainMIPS = fopen("MIPScode.asm", "a");
  // This is the temporary approach, until register management is implemented

    fprintf(mainMIPS, "li $t1,%s\n", id1);
    fprintf(mainMIPS, "li $t2,%s\n", id2);
    fprintf(mainMIPS, "li $t2,$t1\n");

    fclose(mainMIPS);
}

void emitMIPSConstantIntAssignment (int id1, char id2[50]){

    mainMIPS = fopen("MIPScode.asm", "a");
    if (inFunc == 1) {
        mainMIPS = fopen("funcs.asm", "a");
    }
    
  
    fprintf(mainMIPS, "li $t%d,%s\n", id1, id2);

    fclose(mainMIPS);
}

void emitMIPSWriteInt(int n){

    mainMIPS = fopen("MIPScode.asm", "a");
    if (inFunc == 1) {
        mainMIPS = fopen("funcs.asm", "a");
    }

    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(mainMIPS, "li $a0,%s\n", id);
    fprintf(mainMIPS, "# Printing -----------\n");
    fprintf(mainMIPS, "li $v0, 1\n");
    fprintf(mainMIPS, "li $a0, %d\n", n);
    fprintf(mainMIPS, "syscall\n");

    fclose(mainMIPS);
}


void emitMIPSWriteId(char id[50], char type[5]){

    mainMIPS = fopen("MIPScode.asm", "a");

    if (inFunc == 1) {
        mainMIPS = fopen("funcs.asm", "a");
    }
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(mainMIPS, "li $a0,%s\n", id);
    fprintf(mainMIPS, "# Printing -----------\n");

    //if id is an int
    if (strcmp(type, "int") == 0) {
        // printf("printing an integer----->\n");
        fprintf(mainMIPS, "li $v0, 1\n");
        fprintf(mainMIPS, "lw $a0, %s\n", id);
    } 

    //if is a character
    else if (strcmp(type, "char") == 0) {
        // printf("printing a char\n");
        fprintf(mainMIPS, "li $v0, 11\n");
        fprintf(mainMIPS, "lb $a0, %s\n", id);
    }

    // if id is a string
    else { 
        fprintf(mainMIPS, "li $v0, 4\n");
        fprintf(mainMIPS, "la $a0, %s\n", id);
    }

    fprintf(mainMIPS, "syscall\n");    

    fclose(mainMIPS);
}


// ----- ARRAYS FOR MIPS ----->
void emitMIPSArrayDecl (char id[50], int size) {

    dataMIPS = fopen("dataMIPS.asm", "a");

    fprintf(dataMIPS, "%s:  .space   %d\n", id, size*4);

    fclose(dataMIPS);
}

void emitMIPSIntArrayAssign (char id[50], int index, int val) {

    mainMIPS = fopen("MIPScode.asm", "a");

    if (inFunc) {
        mainMIPS = fopen("funcs.asm", "a");
    }

    fprintf(mainMIPS, "addi $s0, $zero, %d\n", val); //add value to register
    fprintf(mainMIPS, "addi $t0, $t0, %d\n", index*4);
    fprintf(mainMIPS, "sw   $s0, %s($t0)\n", id);

    fclose(mainMIPS);
}


void emitMIPSCharDecl (char id[50], char c[5]) {

    dataMIPS = fopen("dataMIPS.asm", "a");

    fprintf(dataMIPS, "%s  .byte   %s\n", id, c);

    fclose(dataMIPS);
}

void setCharVar(char id[50], char c[5]) {

    mainMIPS = fopen("MIPScode.asm", "a");
    if (inFunc == 1) {
        mainMIPS = fopen("funcs.asm", "a");
    }

    fprintf(mainMIPS, "la $a0, %s #get address\n", id);
    fprintf(mainMIPS, "li $a1, %s #new value\n", c);
    fprintf(mainMIPS, "sw $a1 0($a0) #save new value\n");

    fclose(mainMIPS);

}

void emitIntVar(char id[50], int val) {
    // if (inFunc == 1) {
    //     mainMIPS = fopen("funcs.asm", "a");
    // }

    dataMIPS = fopen("dataMIPS.asm", "a");

    fprintf(dataMIPS, "%s:   .word  %d\n", id, val);

    fclose(dataMIPS); 

}

void setIntVar(char id[50], int val) {

    mainMIPS = fopen("MIPScode.asm", "a");

    if (inFunc == 1) {
        mainMIPS = fopen("funcs.asm", "a");
    }

    fprintf(mainMIPS, "la $a0, %s #get address\n", id);
    fprintf(mainMIPS, "li $a1, %d #new value\n", val);
    fprintf(mainMIPS, "sw $a1 0($a0) #save new value\n");

    fclose(mainMIPS);

}

void emitMIPSIfStmt(int ifNum) {

    mainMIPS = fopen("MIPScode.asm", "a");
    if (inFunc == 1) {
        mainMIPS = fopen("funcs.asm", "a");
    }

    fprintf(mainMIPS, "\nfalse%d:\n", ifNum);

    fclose(mainMIPS);

}

void emitMIPSCond(char var1[10], char var2[10], char operator[5], int n) {

    mainMIPS = fopen("MIPScode.asm", "a");
    if (inFunc == 1) {
        mainMIPS = fopen("funcs.asm", "a");
    }

    fprintf(mainMIPS, "li $t0, %s\n", var1);
    fprintf(mainMIPS, "li $t1, %s\n", var2);


    // Basically we use the reverse of the operator becuase
    // the "if" block executes before the "else" block
    if (!strcmp(operator, "!=")) {
        fprintf(mainMIPS, "beq $t0, $t1, false%d\n", n);
	} 
	else if (!strcmp(operator, "==")) {
		fprintf(mainMIPS, "bne $t0, $t1, false%d\n", n);
	}
	else if (!strcmp(operator, ">=")) {
		fprintf(mainMIPS, "ble $t0, $t1, false%d\n", n);
	}
	else if (!strcmp(operator, "<=")) {
		fprintf(mainMIPS, "bge $t0, $t1, false%d\n", n);
	}
	else if (!strcmp(operator, ">")) {
		fprintf(mainMIPS, "blt $t0, $t1, false%d\n", n);
	}
	else if (!strcmp(operator, "<")) {
		fprintf(mainMIPS, "bgt $t0, $t1, false%d\n", n);
	}
    fclose(mainMIPS);

}

void emitMIPSParameters(char *param, int count) {

    mainMIPS = fopen("MIPScode.asm", "a");
    if (inFunc == 1) {
        mainMIPS = fopen("funcs.asm", "a");
    }

    fprintf(mainMIPS, "li $a%d, %s", count, param);

}

void emitMIPSFunc (char func[50]) {

    mainMIPS = fopen("MIPScode.asm", "a");
    funcs = fopen("funcs.asm", "a");
    
    inFunc = 1;

    fprintf(mainMIPS, "jal  %s\n", func);

    fprintf(funcs, "\n%s:\n", func);

    fclose(funcs);
    fclose(mainMIPS);

}

void emitMIPSReturn (char rv[50], char type[50]) {

    funcs = fopen("funcs.asm", "a");

    fprintf(funcs, "li $v1, %s\n", rv);

    fprintf(funcs, "jr  $ra\n");

    fclose(funcs);
    
}

void emitMIPSGetReturn () {

    mainMIPS = fopen("MIPScode.asm", "a");
    if (inFunc == 1) {
        mainMIPS = fopen("funcs.asm", "a");
    }

    fclose(mainMIPS);;

}


void endOfMIPSFunction (char funcName[50]) {

    funcs = fopen("funcs.asm", "a");
    fprintf(funcs, ".end %s\n", funcName);
    inFunc = 0;

    fclose(funcs);

}

void emitEndOfAssemblyCode(){
    mainMIPS = fopen("MIPScode.asm", "a");

    fprintf(mainMIPS, "# -----------------\n");
    fprintf(mainMIPS, "#  Done, terminate program.\n\n");
    // fprintf(mainMIPS, "li $v0,1   # call code for terminate\n");
    // fprintf(mainMIPS, "syscall      # system call (terminate)\n");
    fprintf(mainMIPS, "li $v0,10   # call code for terminate\n");
    fprintf(mainMIPS, "syscall      # system call (terminate)\n");
    fprintf(mainMIPS, ".end main\n");

    fclose(mainMIPS);    
}

void appendFiles() {

    char ch;

    mainMIPS = fopen("MIPScode.asm", "r");
    funcs = fopen("funcs.asm", "r");
    dataMIPS = fopen("dataMIPS.asm", "a");

    fprintf(dataMIPS, "\n");

    while((ch = getc(mainMIPS)) != EOF)
        putc(ch, dataMIPS);

    fprintf(dataMIPS, "\n");

    while((ch = getc(funcs)) != EOF)
        putc(ch, dataMIPS);
 
    // printf("\nCONTENTS COPIED TO FILE: \"dataMIPS.asm\"\n");
    fclose(mainMIPS);
    fclose(funcs);
    fclose(dataMIPS);

}