#include <stdio.h>
#include <string.h>

int max;

void write(char a);

int main(void) 
{
    int i;
    int len1;
    int len2;
    int len3;
    char a;
    char input1[1150];
    char input2[1150];
    char input3[1150]; 
    while (scanf("%s",input1) != EOF) {
        max = 0;
        scanf("%s",input2);
        scanf("%s",input3);

        len1 = strlen(input1);
        len2 = strlen(input2);
        len3 = strlen(input3);

        for (i = 0; i < len1; i++) {
            write(input1[i]);
        }
        for (i = 0; i < len2; i++) {
            write(input2[i]);
        }
        for (i = 0; i < len3; i++) {
            write(input3[i]);
        }

        printf("%d\n",max);
    }

    return 0;
}

void write(char a) 
{
    if ('0' <= a && a <= '9') {
        if (max < a - '0' + 1) {
            max = a - '0' + 1;
        }
    } else if ('A' <= a && a <= 'Z') {
        if (max < a - 'A' + 11) {
            max = a - 'A' + 11;
        }
    } else {
        puts("Found other!!!!!");
        return;
    }
}






