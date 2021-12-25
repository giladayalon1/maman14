#include <stdio.h>
#include <stdlib.h>
#include "assemblerDefine.h"


typedef struct macroNode * macroPtr;

typedef struct macroNode {
        char macroName[MAX_MACRO_LEN];
        char line[MAX_LINE_LEN];
        macroPtr next;
} macro;

void macroPush (macroPtr *macroHead, macroPtr newItem);
int  macroFindVal(macroPtr head, char *macroName);
void macroFreeList (macroPtr *macroHead);

