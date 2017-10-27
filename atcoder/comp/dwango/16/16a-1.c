#include <stdio.h>

int main(void) 
{
    int i, n, count = 0;

    scanf("%d",&n);

    for (i = 25; i <= n; i+=25) {
        count++;
    }

    printf("%d\n",count);

    return 0;
}

