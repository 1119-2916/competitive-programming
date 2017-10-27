#include <stdio.h>
#include <string.h>
#define DATA 1000

int check(char a);

int main(void) 
{
    int i, len;
    char input[DATA];

    fgets(input, DATA, stdin);

    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (check(input[i])) {
            input[i] -= 'a' - 'A';
        }
    }
    printf("%s",input);
    
    return 0;
}

int check(char a)
{
    if ('a' <= a && a <= 'z') {
        return 1;
    } else {
        return 0;
    }
}
