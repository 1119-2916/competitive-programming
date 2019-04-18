#include <stdio.h>

int main(void)
{
    char a;
    int sum = 0;
    while (scanf("%c", &a) != EOF) {
        printf("%d\n", a);
        sum += a;
    }
    printf("%d\n", sum);
    return 0;
}
