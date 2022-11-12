FILE * funcs;

void emitMIPSFuncAssignment(char * id1, char * id2){
    funcs = fopen("funcs.asm", "a");
  // This is the temporary approach, until register management is implemented

    fprintf(funcs, "li $t1,%s\n", id1);
    fprintf(funcs, "li $t2,%s\n", id2);
    fprintf(funcs, "li $t2,$t1\n");

    fclose(funcs);
}

void emitMIPSFuncConstantIntAssignment (int id1, char id2[50]){
    funcs = fopen("funcs.asm", "a");

    funcs = fopen("funcs.asm", "a");
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocateRegister(id1);  // This is conceptual to inform what needs to be done later
    // printf("Emmiting INT mips ------>\n");
    fprintf(funcs, "li $t%d,%s\n", id1, id2);

    fclose(funcs);
}

void emitMIPSFuncWriteInt(int n){
    funcs = fopen("funcs.asm", "a");
    funcs = fopen("funcs.asm", "a");
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(funcs, "li $a0,%s\n", id);
    fprintf(funcs, "# Printing -----------\n");
    fprintf(funcs, "li $v0, 1\n");
    fprintf(funcs, "li $a0, %d\n", n);
    fprintf(funcs, "syscall\n");

    fclose(funcs);
}

void emitMIPSFuncWriteId(char id[50], char type[5]){
    funcs = fopen("funcs.asm", "a");
    funcs = fopen("funcs.asm", "a");
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(funcs, "li $a0,%s\n", id);
    fprintf(funcs, "# Printing -----------\n");

    //if id is an int
    if (strcmp(type, "int") == 0) {
        fprintf(funcs, "li $v0, 1\n");
        fprintf(funcs, "lw $a0, %s\n", id);
    } 

    //if is a character
    else if (strcmp(type, "char") == 0) {
        fprintf(funcs, "li $v0, 11\n");
        fprintf(funcs, "lb $a0, %s\n", id);
    }

    // if id is a string
    else { 
        fprintf(funcs, "li $v0, 4\n");
        fprintf(funcs, "la $a0, %s\n", id);
    }
    fprintf(funcs, "syscall\n");    

    fclose(funcs);
}

// void emitMIPSWriteChar(char id)

void emitMIPSFuncArrayDecl (char id[50], int size) {
    funcs = fopen("funcs.asm", "a");
    dataMIPS = fopen("dataMIPS.asm", "a");

    // int bits = size*4;
    fprintf(dataMIPS, "%s  .BLOCK   %d", id, size);

    fclose(dataMIPS);
}

void emitMIPSFuncCharDecl (char id[50], char c[3]) {
    funcs = fopen("funcs.asm", "a");
    dataMIPS = fopen("dataMIPS.asm", "a");

    fprintf(dataMIPS, "%s  .byte   %s\n", id, c);

    fclose(dataMIPS);
}

void emitMIPSFuncIntVar(char id[50], int val) {
    funcs = fopen("funcs.asm", "a");

    dataMIPS = fopen("dataMIPS.asm", "a ");

    fprintf(dataMIPS, "%s:   .word  %d\n", id, val);

    fclose(dataMIPS); 

}