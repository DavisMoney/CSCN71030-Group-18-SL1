#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"

int main() {
    srand(time(NULL));
    direction d = NONE;
    while (1) {
        d = get_input();
        if (d != NONE) {
            printf("Direction: %d\n", d);
        }
    }
    return 0;
}