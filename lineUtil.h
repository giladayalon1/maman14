#include <ctype.h>
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 
#include "assemblerDefine.h" 

#define NUM_COMMANDS 16

/* Macros for common errors: */

#define ERROR_NOT_A_NUMBER(ch1,ch2) \
        if (!isdigit(ch1)) { \
                    if (ch1 != '-' || !isdigit(ch2)) {\
                                    printf("ERROR - Invalid parameter - not a number\n");\
                                    return;\
                                }\
                }

#define ERROR_EXTRANEOUS_TEXT(ch) \
        if (ch) {\
                    printf("ERROR - Extraneous text after end of command\n");\
                    return;\
                }

#define ERROR_MISSING_PARAMETER(ch) \
        if (!ch) {\
                    printf("ERROR - Missing parameter\n");\
                    return;\
                }

#define ERROR_MISSING_COMMA(ch) \
        if (ch != ',') {\
                    printf("ERROR - Missing comma\n");\
                    return;\
                }

#define ERROR_MULTIPLE_CONSECUTIVE_COMMAS(ch) \
        if (ch == ',') {\
                    printf("ERROR - Multiple consecutive commas\n");\
                    return;\
                }


/* get the command. if it can't find one, it returns -1 */
int getCommand(char *line, int lineNum);

/* Rceives a string and removes the white characters from it */
void removeSpaces(char *str);

/*A function that accepts a char pointer (to the beginning of a number) and returns a pointer to the end of the number */
char *skipNum(char *s);

/*A function that accepts a char pointer and returns a pointer after removing all blanks at the begining */
char *skipBlanks(char *s);

/* get the label. if it can't find one, it returns NULL */
char *getLabel(char* line, int line_num);

/*A function that accepts a char pointer and returns a pointer after the label */
char *skipLabel(char *s);

/* get the command. if it can't find one, it returns NULL */
char *getDotLabel(char* line, char *dot, int line_num);
