#include <stdio.h>

int mem[101], turn;

int main(void)
{
    int i, j, n, tmp, turg[100], count;
    scanf("%d",&n);
    for (i = 0; i <= n; i++) {
        mem[i] = 0;
    }
    scanf("%d",&turn);
    for (i = 0; i < turn; i++) {
        scanf("%d",&turg[i]);
    }
    for (i = 0; i < turn; i++) {
        count = 0;
        for (j = 1; j <= n; j++) {
            scanf("%d",&tmp);
            if (tmp != turg[i]) {
                count++;
            } else {
                mem[j]++;
            }
        }
        mem[turg[i]] += count;
/*
        printf("point:");
        for (j = 1; j <= n; j++) {
            printf("%d ",mem[j]);
        }
        puts("");
*/
    }
    for (i = 1; i <= n; i++) {
        printf("%d\n",mem[i]);
    }
    return 0;
}


