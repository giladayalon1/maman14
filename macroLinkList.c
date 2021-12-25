#include "macroLinkList.h"
#include <unistd.h>


void macroPush(macroPtr *macroHead, macroPtr newItem) {
    macroPtr p1,p2;
    p2 = newItem;
    p2->next = NULL;
    if (*macroHead == NULL) *macroHead = p2;
    else {
        p1 = *macroHead;
        while (p1->next) p1 = p1 -> next;
        p1->next = p2;
    }
}

int macroFindVal(macroPtr macroHead, char *macroName) {
    macroPtr p1;
    int index = 0;

    if (macroHead == NULL) return -1;

    p1 = macroHead;
    while (p1->macroName != macroName) {
        if (p1->next == NULL) return -1;
        p1 = p1->next;
        index++;
    }
    return index;
}

void macroFreeList(macroPtr *macroHead) {
    macroPtr p1;
    while (*macroHead) {
        p1 = *macroHead;
        *macroHead = p1->next;
        free(p1);
    }
    *macroHead = NULL;
}



