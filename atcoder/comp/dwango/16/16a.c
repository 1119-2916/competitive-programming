#include <stdio.h>

int main(void)
{
    int n, count = 0, i;

    scanf("%d",&n);

    for (i = 25; i <= n; i++) {
        if (i % 25 == 0) {
            count++;
        }
    }

    printf("%d\n",count);
    return 0;
}
