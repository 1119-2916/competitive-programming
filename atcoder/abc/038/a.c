#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];
    int i, j;
    int a, b;
    scanf("%s",input);
    a = strlen(input);
    if (input[a-1] == 'T') {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}

