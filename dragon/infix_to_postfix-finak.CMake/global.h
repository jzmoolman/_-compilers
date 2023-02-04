//
// Created by Zach Moolman on 1/29/23.
//
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
int lineno;

struct entry { /* form of symbol table entry */
    char *lexptr;
    int token;
};

extern struct entry symtable[]; /* symbol table */

void init();
int insert();
void error(char *m);
void parse();
int lexan();
int lookup(char s[]);
void emit();



