#include <stdio.h>

int dp[10001];

int main(void)
{
    int n, point[101];
    int i, j, count = 0;

    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d",&point[i]);
    }
    for (i = 1; i < 10001; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (i = 0; i < n; i++) {
        for (j = 10001; j >= 0; j--) {
            if (dp[j]) {
                dp[point[i] + j] = 1;
            }
        }
    }
    for (i = 0; i < 10001; i++) {
        if (dp[i]) {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
