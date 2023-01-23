//
// Created by Piotr Krzyszowski.
//

void printArgs(int argc, char *argv[]) {
    printf("Arguments count: %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("Argument Number %d : %s\n", i, argv[i]);
    printf("\n");
}