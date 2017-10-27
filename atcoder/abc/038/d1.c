#include <stdio.h>

int ans[100001][100001];

int main(void)
{
    int i, j, n;

    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        for (j = 0; j < x; j++) {
            for (k = 0; k < y; k++) {
                ans[j][k]++;
            }
        }
    }

    printf("%d\n",ans[0][0]);
    return 0;
}
