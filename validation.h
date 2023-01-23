//
// Created by Piotr Krzyszowski.
//

#include <string.h>
#include "staticData.h"

int checkInput(char *buf) {

    //usr2 “ls -l | tr a-z A-Z” “fifo”
    int i = 0;
    int size = strlen(buf);
    int j = 0;

    while (buf[i] != ' ' && j <= maxSingleInput) {
        ++i;
        ++j;
    }

    j = 0;
    i+=2;

    while (buf[i] != '"' && j <= maxSingleInput) {
        ++i;
        ++j;
    }

    j = 0;
    i += 3;

    while (buf[i] != '"' && j <= maxSingleInput){
        ++i;
        ++j;
    }

    return ++i == size ? 1 : 0;
}
