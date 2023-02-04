#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isdigit

int lookahead;

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


