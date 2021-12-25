#include <stdio.h>
#include <stdlib.h>
#include "assemblerDefine.h"

typedef enum {
    EXTERNAL, CODE_ENTRY, DATA_ENTRY, CODE, DATA
} symbolAttribute;


typedef struct symbolNode * symbolPtr;

typedef struct symbolNode {
        char symbolName[MAX_SYMBOL_LEN];
        int  value;
        symbolAttribute  attribute;
        symbolPtr next;
} symbol;

void symbolPush (symbolPtr *symbolHead, symbolPtr newItem);
int  symbolFindVal(symbolPtr symbolHead, char *symbolName);
void symbolFreeList (symbolPtr *symbolHead);

