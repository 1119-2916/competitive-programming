#include <stdio.h>

int main(void)
{
    int a = 0, b = 0, i, tmp;

    for (i = 0; i < 4; i++) {
        scanf("%d",&tmp);
        a += tmp;
    }

    for (i = 0; i < 4; i++) {
        scanf("%d",&tmp);
        b += tmp;
    }
    if (a < b) {
    printf("%d\n",b);
    } else {
    printf("%d\n",a);
    }

    return 0;
}

