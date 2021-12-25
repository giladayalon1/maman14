#include "lineUtil.h"

/* an array which stores the acceptable commands */
char *commandNames[] = {"mov", "cmp", "add", "sub", "lea", "clr", "not", "inc", "dec", "jmp", "bne",
                        "jsr", "red", "prn", "rts", "stop"};

/*****************************************/

int getCommand(char *str, int lineNum) {
    int i;
    int count = 0;
    
	str = skipBlanks(str);

    if (str[0] == '\n') { /* check if the line is empty */
        return -1;
    }

    for (i = 0; str[i] != ' ' && str[i] != '\t' && str[i] != ',' && str[i] != '\n'; i++) {
        count++; /* Count how many characters the first word have */
    }
    
    for (i = 0; i < NUM_COMMANDS;   i++) { /* compare the command with each of the command names */
        if (strlen(commandNames[i]) == count && strncmp(commandNames[i], str, count) == 0) /* equals */
            return i;
    }
    return -1; 
}

/*****************************************/

/* Remove all spaces from a given string */
void removeSpaces(char *str) {
    int i;
    int count = 0;
    
/* go through the given string. If current character 
 * is not space or a tab or a newline, then place it at index 'count++'
 */
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            str[count++] = str[i]; 
    }
    
    str[count] = '\0'; /* finish the string */
}

/*****************************************/

char *skipNum(char *s) {
    int i = 0;
    
    if (s[0] == '-' || s[0] == '+')
        i++; /* skip the - sign at the beginning of the number (if there is one) */
    
    for (; isdigit(s[i]); i++) {}
    return s + i; /* return a pointer to the char after the number */
}

/*****************************************/

char *skipBlanks(char *s) {

    while (s[0] == ' ' || s[0] == '\t') s++; /* remove blanks */
    return s; 
}


/*****************************************/

char *skipLabel(char *s) {
    while (s[0] != ':') s++; /* skip everything until colon */
    s = skipBlanks(s); /* skip blanks */
	while (isalnum(*s)) s++; /* skip label name */
    return ++s;
}

/*****************************************/

char *getLabel(char* line, int lineNum) {
	int len = 0;
	char *label;
	char *c = line;

	c = skipBlanks(c);

    if (c[0] == '\n') return NULL;

	/* Iterate the first word in the line, until colon, space or end of line is found
	 * Label must start with a alpha */
	if (!isalpha(*c)) {
		return NULL;
	}

	/* All other characters must be alpha or digit */
	while (isalnum(*c) && len < MAX_LABEL_LEN-1) {
		c++;
		len++;
	}

	if (isalpha(*c)) {
        printf("ERROR in line %d - label has more charecters than allowed. Consider increase MAX_LABEL_LEN\n",lineNum);
		return NULL;
	}

	if (line[len] == ':') {
		/* Label found. */
        label = (char*)malloc(MAX_LABEL_LEN);
        if (!label) {
    	    printf("ERROR during getLabel - Can't allocate memory to label\n");
            exit(0);
        }
		strncpy(label, line, len);
		label[len] = '\0';
		return label;
	}

	return NULL;
}

/*****************************************/

char *getDotLabel(char* line, char* dot, int lineNum) {
    int len = 0;
	int try;
    char *label;
    char *c = line;

    c = skipBlanks(c);

    if (c[0] == '\n') return NULL;

	try = strncmp(c, dot, strlen(dot));
	if (try != 0) return NULL;
	c+=strlen(dot);

    if (c[0] != ' ' && c[0] != '\t') {
        printf("ERROR in line %d - after %s must be space or tab\n",lineNum, dot);
		return NULL;
	}
	c++;
    c = skipBlanks(c);

    /* Iterate the first word in the line.
     * Label must start with an alpha */
    if (!isalpha(*c)) {
        return NULL;
    }

    /* Label found. */
    label = (char*)malloc(MAX_LABEL_LEN);
    if (!label) {
        printf("ERROR during getExtern - Can't allocate memory to label\n");
        exit(0);
    }

    label = c;

    /* All other characters must be alpha or digit */
    while (isalnum(*c) && len < MAX_LABEL_LEN-1) {
        c++;
        len++;
    }

    if (isalpha(*c)) {
        printf("ERROR in line %d - extern label has more charecters than allowed. Consider increase MAX_LABEL_LEN\n",lineNum);
        free(label);
        return NULL;
    }
    c = skipBlanks(c);
    if (c[0] != '\n') {
        printf("ERROR in line %d - Charecters after %s command are not allowed\n",lineNum, dot);
        free(label);
        return NULL;
    } 

    label[len] = '\0';
    return label;
}


