#include <stdio.h>

int main(void)
{
    int a, b, c, tmp;
    scanf("%d %d %d", &a, &b, &c);

    if (b > c) {
        tmp = c;
        c = b; 
        b = tmp;
    }

    if (a > b) {
        tmp = a;
        a = b; 
        b = tmp;
    }

    if (b > c) {
        tmp = c;
        c = b; 
        b = tmp;
    }

    printf("%d %d %d\n", a, b, c);

    return 0;
}





