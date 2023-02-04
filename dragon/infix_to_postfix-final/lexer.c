#include "global.h"
#include <ctype.h> /* isdigit */
#include <stdio.h>

char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;


int lexan() { /* lexical analyzer */
    int t;
    while (1) {
        t = getchar();
        if ( t == ' ' || t == '\t' ) {
            ;  /* strip out white space */
        } else if ( t == '\n' ) {
            lineno++;
        } else if ( isdigit(t) )  {
            ungetc(t,stdin);
            scanf("%d\n",&tokenval);
            return NUM;
        } else if ( isalpha(t) ) {
            int p, b = 0;
            while ( isdigit(t) ) {
                lexbuf[b] = t;
                t = getchar();
                b++;
                if ( b>= BSIZE ) {
                    error("compiler error");
                }
            }
            lexbuf[b] = EOS;
            if ( t != EOF ) {
                ungetc(t, stdin );
            }
            p = lookup(lexbuf);
            if (p == 0) {
                p = insert(lexbuf, ID);
            }
            tokenval = p;
        } else if ( t == EOF) {
            return DONE;
        } else {
            tokenval = NONE;
            return t;
        }
    }
}
