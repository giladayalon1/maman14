#include "assemblerDefine.h"
#include "firstPass.h"

/*****************************************/

int firstPass (char *fileName) {
    FILE *filePtr;
    char line[MAX_LINE_LEN];
    int lineNum = 0;
    int okFlag = 1;

    if ((filePtr = fopen(strcat(fileName,".as"),"r")) == NULL) {
        printf("ERROR - Can't open %s\n",fileName);
        return 0;
    }

    while(fgets(line, MAX_LINE_LEN, filePtr)) {
        lineNum++;
        printf("======================\n%s", line);
        okFlag = (okFlag & firstPassHandleLine(line, lineNum));
    }

    fclose(filePtr);
    return okFlag;
}

/*****************************************/

int firstPassHandleLine(char line[], int lineNum) {
    int command;
    char *str;
    char *label;
    char *externLabel;
    char *entryLabel;

    str = line;

    str = skipBlanks(str);

    if (str[0] == '\n') return 1; /* empty line */
    if (str[0] == ';') return 1; /* comment */

    label = getLabel(str, lineNum);
    if (label != NULL) {
        printf("Label found = \"%s\"\n",label);
        str = skipLabel(str);
    }

    externLabel = getDotLabel(str, ".extern", lineNum);
    if (externLabel != NULL) {
        printf(".extern found = \"%s\"\n",externLabel);
    }

    entryLabel = getDotLabel(str, ".entry", lineNum);
    if (entryLabel != NULL) {
        printf(".entry found = \"%s\"\n",entryLabel);
    }


    command = getCommand(str, lineNum); /* get command */
    if (command >=0) {
        printf("Found a command \"%s\"\n",commandNames[command]);
        str += strlen(commandNames[command]); /* skip command name */
        removeSpaces(str); /* remove spaces, tabs or newline from the rest of the command */
    }

    
    
    if (str[0] == ',') { /* checks if the first character is a comma */
        printf("ERROR in line %d - Illegal comma\n",lineNum);
        return 0;
    }
    
    /* OK */
    free(label);
    return 1;
    
}
    
