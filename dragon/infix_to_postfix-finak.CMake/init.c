//
// Created by Zach Moolman on 1/29/23.
//

#include "global.h"

struct entry keywords[] = {
        "div", DIV,
        "mod", MOD,
        0, 0
};

void init() {
//    printf("init\n");
    struct  entry *p;
    for ( p = keywords; p->token; p++){
        insert(p->lexptr, p->token);
    }
}