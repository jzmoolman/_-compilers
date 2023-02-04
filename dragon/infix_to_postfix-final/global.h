#include <stdio.h>
#include <ctype.h>

#define BSIZE 128 /* buffer size */
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

extern int tokenval; /* value of token */
extern int lineno;

struct entry { /* form of symbol table entry */
    char *lexptr; 
    int token;
};

extern struct entry symtable[]; /* symbol table */

extern void init();
extern void parse();
extern int lexan();
extern void emit();
extern void error(char *m);
extern int lookup(char s[]);
extern int insert();



