#include <stdio.h>

int main(void)
{
    //puts("10");
    for (int i = 0; i < 10; i++) {
        puts("1000 1");
        for (int j = 0; j < 1000; j++) {
            printf("%d 1\n", j);
        }
    }
    puts("0 0");
    return 0;
}
