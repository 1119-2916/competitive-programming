#include <stdio.h>

int main(void) {
    int i, j;
    puts("200");
    for(i = 0; i < 200; i++) {
        puts("1000");
        for(j = 0; j < 500; j++) {
            printf(".X");
        }
        puts("");
        for(j = 0; j < 500; j++) {
            printf("X.");
        }
        puts("");
    }
    return 0;
}
