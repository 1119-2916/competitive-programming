#include <stdio.h>
#include <string.h>

char data[202];
int n;

int main(void) 
{
    int i, j, k;

    scanf("%d",&n);
    scanf("%s",data);
    if (!(n % 2))  {
        puts("-1");
        return 0;
    }
    if (n == 1) {
        if (data[i] == 'b') {
            puts("0");
            return 0;
        } else {
            puts("-1");
            return 0;
        }
    }

    for (i = n/2 + 1, j = n/2 - 1, k = 1; i < n; i++, j--, k++) {
        if (k % 3 == 1) {
            if (data[i] != 'c') {
                puts("-1");
                return 0;
            }
            if (data[j] != 'a') {
                puts("-1");
                return 0;
            }
        }
        if (k % 3 == 2) {
            if (data[i] != 'a') {
                puts("-1");
                return 0;
            }
            if (data[j] != 'c') {
                puts("-1");
                return 0;
            }
        }
        if (k % 3  == 0) {
            if (data[i] != 'b') {
                puts("-1");
                return 0;
            }
            if (data[j] != 'b') {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n",n/2);
    return 0;
}

