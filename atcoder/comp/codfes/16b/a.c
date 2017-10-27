#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max(a, b) a<b?b:a
#define min(a, b) a>b?b:a
#define INF 1010001000

int n;
int bef[100001], aft[100001];
char s[100001];

int main(void)
{
    int i, j, a, b;
    int max, min, sum = 0;
    char cod[100] = "CODEFESTIVAL2016";
    
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++) {
        if (cod[i] != s[i]) {
            sum++;
        }
    }

    printf("%d\n",sum);




    return 0;
}





