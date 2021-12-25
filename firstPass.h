#include "lineUtil.h"
#include "symbolLinkList.h"
#include <string.h>
#include <stdio.h>

extern char *commandNames[];

/* Receives an input line and handle it (does the command or prints an error) */
int firstPassHandleLine(char line[], int lineNum);

