
// Set of functions to emit MIPS code
FILE * MIPScode;
FILE * dataMIPS;
FILE * funcs;

void  initAssemblyFile(){
    // Creates a MIPS file with a generic header that needs to be in every file

    MIPScode = fopen("MIPScode.asm", "w");
    dataMIPS = fopen("dataMIPS.asm", "w");
    funcs = fopen("funcs.asm", "w");
    
    fprintf(MIPScode, ".text\n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "# -----------------------\n");

    // data
    fprintf(dataMIPS, ".data\n");
    fprintf(dataMIPS, "newLine: .asciiz \"\\n\"\n");


    fclose(MIPScode);
    fclose(dataMIPS);
    fclose(funcs);

}

void emitMIPSAssignment(char * id1, char * id2){
    MIPScode = fopen("MIPScode.asm", "a");
  // This is the temporary approach, until register management is implemented

    fprintf(MIPScode, "li $t1,%s\n", id1);
    fprintf(MIPScode, "li $t2,%s\n", id2);
    fprintf(MIPScode, "li $t2,$t1\n");

    fclose(MIPScode);
}

void emitMIPSConstantIntAssignment (int id1, char id2[50]){
    funcs = fopen("funcs.asm", "a");

    MIPScode = fopen("MIPScode.asm", "a");
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocateRegister(id1);  // This is conceptual to inform what needs to be done later
    // printf("Emmiting INT mips ------>\n");
    fprintf(MIPScode, "li $t%d,%s\n", id1, id2);

    fclose(MIPScode);
}

void emitMIPSWriteInt(int n){
    funcs = fopen("funcs.asm", "a");
    MIPScode = fopen("MIPScode.asm", "a");
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(MIPScode, "li $a0,%s\n", id);
    fprintf(MIPScode, "# Printing -----------\n");
    fprintf(MIPScode, "li $v0, 1\n");
    fprintf(MIPScode, "li $a0, %d\n", n);
    fprintf(MIPScode, "syscall\n");

    fclose(MIPScode);
}

void emitMIPSWriteId(char id[50], char type[5]){
    funcs = fopen("funcs.asm", "a");
    MIPScode = fopen("MIPScode.asm", "a");
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(MIPScode, "li $a0,%s\n", id);
    fprintf(MIPScode, "# Printing -----------\n");

    //if id is an int
    if (strcmp(type, "int") == 0) {
        fprintf(MIPScode, "li $v0, 1\n");
        fprintf(MIPScode, "lw $a0, %s\n", id);
    } 

    //if is a character
    else if (strcmp(type, "char") == 0) {
        fprintf(MIPScode, "li $v0, 11\n");
        fprintf(MIPScode, "lb $a0, %s\n", id);
    }

    // if id is a string
    else { 
        fprintf(MIPScode, "li $v0, 4\n");
        fprintf(MIPScode, "la $a0, %s\n", id);
    }
    fprintf(MIPScode, "syscall\n");    

    fclose(MIPScode);
}

// void emitMIPSWriteChar(char id)

void emitMIPSArrayDecl (char id[50], int size) {
    funcs = fopen("funcs.asm", "a");
    dataMIPS = fopen("dataMIPS.asm", "a");

    // int bits = size*4;
    fprintf(dataMIPS, "%s  .BLOCK   %d", id, size);

    fclose(dataMIPS);
}

void emitMIPSCharDecl (char id[50], char c[3]) {
    funcs = fopen("funcs.asm", "a");
    dataMIPS = fopen("dataMIPS.asm", "a");

    fprintf(dataMIPS, "%s  .byte   %s\n", id, c);

    fclose(dataMIPS);
}

void emitIntVar(char id[50], int val) {
    funcs = fopen("funcs.asm", "a");

    dataMIPS = fopen("dataMIPS.asm", "a ");

    fprintf(dataMIPS, "%s:   .word  %d\n", id, val);

    fclose(dataMIPS); 

}

void emitMIPSFunc (char func[10]) {
    funcs = fopen("funcs.asm", "a");

    fprintf(funcs, "%s:\n", func);

    fclose(funcs);

}

void emitEndOfAssemblyCode(){
    MIPScode = fopen("MIPScode.asm", "a ");

    fprintf(MIPScode, "# -----------------\n");
    fprintf(MIPScode, "#  Done, terminate program.\n\n");
    // fprintf(MIPScode, "li $v0,1   # call code for terminate\n");
    // fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, "li $v0,10   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, ".end main\n");

    fclose(MIPScode);    
}

void addMainToData() {

    MIPScode = fopen("MIPScode.asm", "a+");
    dataMIPS = fopen("dataMIPS.asm", "a+");
    funcs = fopen("funcs.asm", "a+");
 
    // If file is not found then return.
    if (!MIPScode && !dataMIPS && !funcs) {
        printf("Unable to open/"
               "detect file(s)\n");
        return;
    }
 
    char buf[100];
 
    // explicitly writing "\n"
    // to the destination file
    // so to enhance readability.
    fprintf(dataMIPS, "\n");
 
    // writing the contents of
    // source file to destination file.
    while (!feof(MIPScode)) {
        fgets(buf, sizeof(buf), MIPScode);
        fprintf(dataMIPS, "%s", buf);
    }
    
    fclose(MIPScode);
    
    //fclose(my_life);
    
    fprintf(dataMIPS, "\n");

    while (!feof(funcs)) {
        fgets(buf, sizeof(buf), funcs);
        fprintf(dataMIPS, "%s", buf);
    }

    fclose(funcs);
 
    // rewind(dataMIPS);
 
    // printing contents of
    // destination file to stdout.
    // while (!feof(dataMIPS)) {
    //     fgets(buf, sizeof(buf), dataMIPS);
    //     printf("%s", buf); //Prints result to console if needed
    // }
}   