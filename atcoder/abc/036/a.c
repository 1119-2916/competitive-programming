#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d",&a, &b);
    if (b % a) {
        printf("%d\n",b/a+1);
    } else {
        printf("%d\n",b/a);
    }
    return 0;
}
