#include <stdio.h>

int main(void)
{
    char a, b;
    scanf("%c %c",&a, &b);
    if (a - 'A' == b - 'a') {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}

