#include <stdio.h>

char bo[16];

int check(char a);

int main(void)
{
    int i, j;
    char tmp;

    while (i <= 15) {
        tmp = getchar();
        if (check(tmp)) {
            bo[i] = tmp;
            i++;
        }
    }

    for (i = 15; i >= 0; i--) {
        printf("%c",bo[i]);
        if (i % 4) {
            printf(" ");
        } else {
            puts("");
        }
    }

    return 0;
}

int check(char a) 
{
    if (a == 'o' || a == 'x' || a == '.') {
        return 1;
    } else {
        return 0;
    }
}





