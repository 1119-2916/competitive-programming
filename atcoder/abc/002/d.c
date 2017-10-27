#include <stdio.h>

int mem[12][12];
int ans[12];
int n, m;

int main(void)
{
    int i, j;
    int tmp1, tmp2;

    scanf("%d %d",&n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d",&tmp1, &tmp2);
        mem[tmp1-1][tmp2-1] = 1;
        mem[tmp2-1][tmp1-1] = 1;
    }

    for (i = 0; i < n; i++) {
        tmp1 = 0;
        for (j = 0; j < n; j++) {
            if (mem[i][j]) {
                tmp1++;
            }
        }
        ans[i] = tmp1;
    }

    tmp1 = ans[0];

    for (i = 1; i < n; i++) {
        if (tmp1 < ans[i]) {
            tmp1 = ans[i];
        }
    }
     
    printf("%d\n",tmp1+1);

    return 0;
}





