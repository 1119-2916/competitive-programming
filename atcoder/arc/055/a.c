#include <stdio.h>

int main(void)
{
    int n, i;
    scanf("%d",&n);
    if (n) {
        printf("1");
    }
    for (i = 1; i < n; i++) {
        printf("0");
    }
    printf("7\n");
    return 0;
}

