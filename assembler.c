#include "assembler.h"

/* The main method: */
int main(int argc, char *argv[]) {
    int fileCount; 

    if (argc==1) {
        printf("ERROR - no files given \n");
        return 0;
    }

    for (fileCount = 1; fileCount < argc; fileCount++) 
        assembler(argv[fileCount]);
    return 0;
}

/*************************************/

void assembler(char *fileName) {
    int okFlag;

    /*
    okFlag = preAssembler(fileName);
    */
    okFlag = firstPass(fileName);
    if (okFlag) printf ("firstPass ok\n");
    else printf ("firstPass failed\n");
}

