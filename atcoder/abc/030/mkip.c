#include <stdio.h>

int main(void)
{
    int i;
    printf("100000 100000\n");
    printf("1 1\n");

    for (i = 0; i < 100000; i++) {
        printf("%d ",i+1);
    }
    puts("");
    for (i = 0; i < 100000; i++) {
        printf("%d ",i+1);
    }
    puts("");

    return 0;
}
