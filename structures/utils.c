
#include <stdio.h>
#include"../include/utils.h"

void clearScreen() {
    // Clear the console screen (works on most terminals)
    printf("\033[H\033[J");
}
