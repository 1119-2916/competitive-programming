#include <stdio.h>
#include <math.h>

int n;

void write_pass(int num, int count);

int main(void)
{
    int i;

    scanf("%d",&n);

    for (i = 0; i < (int)pow(3.0, (double)n); i++) {
        write_pass(i, 0);
        puts("");
    }
    return 0;
}

void write_pass(int num, int count)
{
    int tmp;
    if (count == n) {
        return ;
    }
    tmp = num % 3;
    write_pass(num/3, count+1);
    printf("%c",'a'+tmp);
}
