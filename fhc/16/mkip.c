#include <stdio.h>

int main(void) {
    int i, j;
    puts("50");
    for(i = 0; i < 50; i++) {
        puts("2000");
        for(j = 0; j < 2000; j++) {
            printf("%d %d\n",j, j);
        }
    }
    return 0;
}

