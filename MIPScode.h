
// Set of functions to emit MIPS code
FILE * mainMIPS;
FILE * dataMIPS;
FILE * funcs;

char currentScope[50];

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
    funcs = fopen("funcs.asm", "a");

    mainMIPS = fopen("MIPScode.asm", "a");
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocateRegister(id1);  // This is conceptual to inform what needs to be done later
    // printf("Emmiting INT mips ------>\n");
    fprintf(mainMIPS, "li $t%d,%s\n", id1, id2);

    fclose(mainMIPS);
}

void emitMIPSWriteInt(int n){
    funcs = fopen("funcs.asm", "a");
    mainMIPS = fopen("MIPScode.asm", "a");
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
    funcs = fopen("funcs.asm", "a");
    mainMIPS = fopen("MIPScode.asm", "a");
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(mainMIPS, "li $a0,%s\n", id);
    fprintf(mainMIPS, "# Printing -----------\n");

    //if id is an int
    if (strcmp(type, "int") == 0) {
        fprintf(mainMIPS, "li $v0, 1\n");
        fprintf(mainMIPS, "lw $a0, %s\n", id);
    } 

    //if is a character
    else if (strcmp(type, "char") == 0) {
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
    funcs = fopen("funcs.asm", "a");
    dataMIPS = fopen("dataMIPS.asm", "a");

    fprintf(dataMIPS, "%s  .space   %d\n", id, size*4);

    fclose(dataMIPS);
}

void emitMIPSIntArrayAssign (char id[50], int index, int val) {

    mainMIPS = fopen("MIPScode.asm", "a");

    fprintf(mainMIPS, "addi $s0, $zero, %d\n", val); //add value to register
    fprintf(mainMIPS, "addi $t0, $t0, %d\n", index*4);
    fprintf(mainMIPS, "sw   $s0, %s(t0)\n", id);

    fclose(dataMIPS);
}


void emitMIPSCharDecl (char id[50], char c[5]) {
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


void emitMIPSFunc (char func[50]) {
    mainMIPS = fopen("MIPScode.asm", "a");
    funcs = fopen("funcs.asm", "a");
    strcpy(currentScope, func);

    fprintf(mainMIPS, "jal  %s", func);

    fprintf(funcs, "%s:\n", func);

    fclose(funcs);

}

void emitEndOfAssemblyCode(){
    mainMIPS = fopen("MIPScode.asm", "a ");

    fprintf(mainMIPS, "# -----------------\n");
    fprintf(mainMIPS, "#  Done, terminate program.\n\n");
    // fprintf(mainMIPS, "li $v0,1   # call code for terminate\n");
    // fprintf(mainMIPS, "syscall      # system call (terminate)\n");
    fprintf(mainMIPS, "li $v0,10   # call code for terminate\n");
    fprintf(mainMIPS, "syscall      # system call (terminate)\n");
    fprintf(mainMIPS, ".end main\n");

    fclose(mainMIPS);    
}

void addMainToData() {

    mainMIPS = fopen("MIPScode.asm", "a+");
    dataMIPS = fopen("dataMIPS.asm", "a+");
    funcs = fopen("funcs.asm", "a+");
 
    // If file is not found then return.
    if (!mainMIPS && !dataMIPS && !funcs) {
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
    while (!feof(mainMIPS)) {
        fgets(buf, sizeof(buf), mainMIPS);
        fprintf(dataMIPS, "%s", buf);
    }
    
    fclose(mainMIPS);
    
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