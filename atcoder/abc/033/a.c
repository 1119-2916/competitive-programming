#include <stdio.h>

char input[5];

int main(void)
{
    int i, j;
    scanf("%s",input);
    for (i = 0; i < 3; i++) {
        if (input[i] != input[i+1]) {
            puts("DIFFERENT");
            return 0;
        }
    }
    puts("SAME");
    return 0;
}

