#include <stdio.h>

int main(void)
{
    puts("200000");
    for (int i = 0; i < 200000; i++) {
        printf("%d ", i+1);
    }

    return 0;
}
