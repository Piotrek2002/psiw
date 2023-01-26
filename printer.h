//
// Created by Piotr Krzyszowski.
//
#include "logLibrary.h"

void printArgs(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++)
        printf(argumentsNumber, i, argv[i]);
    printf(newLine);
}
