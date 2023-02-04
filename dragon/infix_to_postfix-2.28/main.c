#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isdigit
                   
#define NUM 256

int lookahead;
int lineno = 1;
int tokenval = 0;


int lexan();
int expr();
int term();
int match(int t);
int error();


int main() {
    lookahead = getchar();
    expr();
    putchar('\n');

    return 0;
}

int lexan() {
    int t;
    while (1) {
        t = getchar();
        if ( t == ' ' ||  t == '\t' ) {
            // do nothing
        } else if ( t == '\n') {
            lineno++;
            
        } else if ( isdigit(t) ) {
            tokenval = t = '0';
            t = getchar();
            while ( isdigit(t) ){
                tokenval = tokenval*10 + t-'0';
                t = getchar();
            }
            ungetc(t, stdin);
        return NUM;
        } else {
            tokenval = 0;
            return t;
        }
    }
}

int expr() {
    term();
    while (1) {
        if (lookahead == '+') {
            match('+');
            term();
            putchar('+');
        } else if (lookahead == '-') {
            match('-');
            term();
            putchar('-');
        } else break;
    }
    return 0;
}

int term() {
    if (isdigit(lookahead)) {
        putchar(lookahead);
        match(lookahead);
    } else error();
    return 0;
}

int match(int t) {
    if (lookahead == t) {
        lookahead = getchar();
    } else error();
    return 0;
}

int error(){
    printf("syntax error\n");
    exit(1);
    return 0;
}


