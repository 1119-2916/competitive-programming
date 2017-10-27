#include <stdio.h>

int main(void)
{
    int i, count;

    for (i = 1000000000, count = 0; count < 100; 
            count++, i -= 2) {

        printf("%d\n", i);
    }

    return 0;
}


