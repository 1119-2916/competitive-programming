#include <stdio.h>
#define N 100000

int main(void)
{
    int i;

    printf("%d\n",N);

    for (i = 1; i <= N; i++) {
        printf("%d ",N - i);
    }
    puts("");
    return 0;
}
