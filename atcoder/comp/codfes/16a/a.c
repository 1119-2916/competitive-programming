#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



int main(void)
{
    int a, b, i, j, length;
    char input[10001];

    scanf("%s", input);

    for (i = 0; i < 4; i++) {
        printf("%c", input[i]);
    }
    printf(" ");
    for (; i < 12; i++) {
        printf("%c", input[i]);
    }
    puts("");


    return 0;
}
