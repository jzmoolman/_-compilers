//
// Created by Zach Moolman on 1/29/23.
//

#include <stdlib.h>
#include "global.h"

void error(char *m) {
    fprintf(stderr, "line %d: %s\n", lineno, m);
    exit(1);
}

