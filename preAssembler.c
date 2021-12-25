#include "preAssembler.h"
#include "macroLinkList.h"

/*****************************************/

int preAssembler (char *fileName) {
    FILE *filePtr;
    char line[MAX_LINE_LEN];
    macroPtr macroHead = NULL;
   	macroPtr newItem;
    macroPtr p1;
    int okFlag = 1;

    if ((filePtr = fopen(strcat(fileName,".as"),"r")) == NULL) {
        printf("ERROR - Can't open %s\n",fileName);
        return 0;
    }

    while(fgets(line, MAX_LINE_LEN, filePtr)) {
    	newItem = (macroPtr) malloc(sizeof(macro));
    	if (!newItem) {
        	printf("ERROR during preAssembler of %s - Can't allocate memory\n",fileName);
        	exit(0);
		}
		strcpy(newItem->line, line);
        macroPush(&macroHead, newItem);
    }

    printf("Link List =  ");
    p1 = macroHead;
    while (p1) {
        printf("%s",p1->line);
        p1 = p1->next;
    }


    fclose(filePtr);
    macroFreeList(&macroHead);
    return okFlag;
}
