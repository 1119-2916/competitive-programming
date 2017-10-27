#include <stdio.h>
#include <string.h>

char input[11][12];

int main(void)
{
    int count = 0, i;

    for (i = 0; i < 12; i++) {
        scanf("%s",input[i]);
    }

    for (i = 0; i < 12; i++) {
        if (strchr(input[i], 'r')) {
            count++;
        }
    }

    printf("%d\n",count);

    return 0;
}

