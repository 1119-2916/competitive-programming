#include <stdio.h>
#include <string.h>

char input[1001];

int main(void)
{
    int i, j, len;
    scanf("%s",input);
    len = strlen(input);
    for (i = 0; i < len; i++) {
        if ('A' == input[i] ) {
            input[i] = 'X';
        } else if ('B' == input[i]) {
            input[i] = 'Y';
        } else if ('C' == input[i]) {
            input[i] = 'Z';
        } else {
        input[i] -= 3;
        }
    }
    printf("%s\n",input);
    return 0;
}

