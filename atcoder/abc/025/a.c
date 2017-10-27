#include <stdio.h>

char input[6];
int n;

int main(void)
{
    int i;

    scanf("%s",input);
    scanf("%d",&n);

    printf("%c%c\n",input[n/5], input[n%5-1]);

    return 0;
}
