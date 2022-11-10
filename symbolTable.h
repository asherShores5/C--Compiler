//Symbol table header
#include <string.h>

struct Entry
{
	int itemID;
	char itemName[50];  //the name of the identifier
	char itemKind[8];  //is it a function or a variable?
	char itemType[8];  // Is it int, char, etc.?
    char itemValue[25];
	char scope[50];     // global, or the name of the function
	int itemUsed;
};

struct Entry symTabItems[100];
int symTabIndex = 0;
int SYMTAB_SIZE = 20;

void symTabAccess(void){
	printf("\n::::> Symbol table accessed.\n\n");
}

void addItem(char itemName[50], char itemKind[8], char itemType[8], char scope[50]){
	

		// what about scope? should you add scope to this function?
		symTabItems[symTabIndex].itemID = symTabIndex;
		strcpy(symTabItems[symTabIndex].itemName, itemName);
		strcpy(symTabItems[symTabIndex].itemKind, itemKind);
		strcpy(symTabItems[symTabIndex].itemType, itemType);
        strcpy(symTabItems[symTabIndex].itemValue, "NULL");
		strcpy(symTabItems[symTabIndex].scope, scope);
		symTabItems[symTabIndex].itemUsed = 0;
		symTabIndex++;
	
}

void showSymTable() {
	printf("itemID    itemName    itemKind    itemType  itemValue  itemSope    itemUsed?\n");
	printf("----------------------------------------------------------------------------\n");
	for (int i=0; i<symTabIndex; i++){
		printf("%5d  %10s  %10s  %10s %10s %10s %10d \n",symTabItems[i].itemID, symTabItems[i].itemName, symTabItems[i].itemKind, symTabItems[i].itemType, symTabItems[i].itemValue, symTabItems[i].scope, symTabItems[i].itemUsed);
	}	

	printf("----------------------------------------------------------------------------\n\n");
}

int found(char itemName[50], char scope[50]) {
    // Lookup an identifier in the symbol table
    // what about scope?
    // return TRUE or FALSE
    // Later on, you may want to return additional information

    // Dirty loop, becuase it counts SYMTAB_SIZE times, no matter the size of the symbol table

    for(int i=0; i < SYMTAB_SIZE; i++){

		int isGlobal = strcmp(symTabItems[i].scope, "GLOBAL");

        int str1 = strcmp(symTabItems[i].itemName, itemName);
        //printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);

        int str2 = strcmp(symTabItems[i].scope,scope);
        //printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);

        if( str1 == 0 && (str2 == 0 || isGlobal == 0)) {
            return 1; // found the ID in the table
        }
    }

    return 0;
}

int getSymTabIndex() {
    return symTabIndex; //Genius method for index retrieval: copyright Evan Kliwer
}

// Adds value to an ID in the symbol table
int setItemValue(char itemName[50], char itemValue[50], char scope[50]) {
	
	for (int i = 0; i < SYMTAB_SIZE; i++) {
		int isGlobal = strcmp(symTabItems[i].scope, "GLOBAL");
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope);
		
		if (str1 == 0 && (isGlobal == 0 || str2 == 0)) {
			strcpy(symTabItems[i].itemValue, itemValue);
			printf("\nValue: %s added to item: %s\n\n", itemValue, symTabItems[i].itemName);
			showSymTable();
			return 1; //value added 
		}
	}

	printf("Item %s was not found\n", itemName);	
	return 0;
}

// Returns the value of a given ID
int getValue(char itemName[50], char scope[50]) {

	int returnValue;

	for(int i=0; i<100; i++) {
		int isGlobal = strcmp(symTabItems[i].scope, "GLOBAL");
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope);

		if( str1 == 0 && (str2 == 0 || isGlobal == 0)){
			returnValue = atoi(symTabItems[i].itemValue);
			printf("Item Value:%d\n", returnValue);
			return returnValue;
		}
	}

	return 0; //item not found;
}

// Returns the ID of a given itemName
int getItemID(char itemName[50], char scope[50]) {

	for(int i=0; i<100; i++) {
		int isGlobal = strcmp(symTabItems[i].scope, "GLOBAL");
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope, scope);
		if( str1 == 0 && (str2 == 0 || isGlobal == 0)){
			return symTabItems[i].itemID;
		}
	}

	return -1; //item not found
}

const char* getVariableType(char itemName[50], char scope[50]){
    //char *name = "int";
    //return name;
    for(int i=0; i<SYMTAB_SIZE; i++){

		int isGlobal = strcmp(symTabItems[i].scope, "GLOBAL");
        int str1 = strcmp(symTabItems[i].itemName, itemName);
        //printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
        int str2 = strcmp(symTabItems[i].scope,scope);
        //printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
        if( str1 == 0 && (str2 == 0 || isGlobal == 0)){
			// printf("Debug\n\n");
            return symTabItems[i].itemType; // found the ID in the table
        }
    }
    return NULL;
}

int compareTypes(char itemName1[50], char itemName2[50], char scope[50]){
    const char* idType1 = getVariableType(itemName1, scope);
    const char* idType2 = getVariableType(itemName2, scope);
    
    printf("%s = %s\n", idType1, idType2);
    
    int typeMatch = strcmp(idType1, idType2);
    if(typeMatch == 0){
        return 1; // types are matching
    }
    else return 0;
}