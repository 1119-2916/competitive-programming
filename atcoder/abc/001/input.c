#include <stdio.h>

int main(void)
{
    int i;
    puts("2400");
    for (i = 0; i < 2401; i++) {
        if (i < 10) {
            printf("0000-000%d\n",i);
        } else if (i < 100) {
            printf("0000-00%d\n",i);
        } else if (i < 1000) {
            printf("0000-0%d\n",i);
        } else {
            printf("0000-%d\n",i);
        }
    }
    return 0;
}


