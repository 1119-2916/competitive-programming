#include <stdio.h>
#include <string.h>

int sum, n;
int input[1000];
char name[1000][21];

int main(void)
{
    int i;

    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        scanf("%s %d",name[i], &input[i]);
        sum += input[i];
    }


    for (i = 0; i < n; i++) {
        if (input[i] > sum/2) {
            printf("%s\n",name[i]);
            return 0;
        }
    }

    puts("atcoder");
    return 0;
}

