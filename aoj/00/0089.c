#include <stdio.h>
#include <math.h>

int dp[100][100];
int dy[100][100];
int data[10000];

int max(int a, int b);

int main(void)
{
    int i = 0, j, n, tmp, k;

    while (scanf("%d,", &data[i++]) != EOF);
    n = (-2+sqrt(4-4*(1-i)))/2;
    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            dy[i][j] = data[k++];
        }
    }
    for (i = 0; i < n+1; i++) {
        dy[n][i] = data[k++];
    }
    for (i = n+1; i < n+n+1; i++) {
        for (j = 0; j < n+n+1-i; j++) {
            dy[i][j] = data[k++];
        }
    }


    dp[0][0] = dy[0][0];
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + dy[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + dy[i+1][j+1]);
        }
    }
    dp[n+1][0] = dp[n][0]+dy[n+1][0];
    dp[n+1][n-1] = dp[n][n]+dy[n+1][n-1];
    for (i = 1; i < n; i++) {
        dp[n+1][i] = max(dp[n+1][i], dp[n][i] + dy[n+1][i]);
        dp[n+1][i-1] = max(dp[n+1][i-1], dp[n][i] + dy[n+1][i-1]);
    }
    for (i = n+1; i < n+n+1; i++) {
        for (j = 0; j < n+n+1-i; j++) {
            if (!j) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + dy[i+1][j]);
            } else if (j == n+n-i) {
                dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + dy[i+1][j-1]);
            } else {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + dy[i+1][j]);
                dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + dy[i+1][j-1]);
            }
        }
    }
    printf("%d\n",dp[i-1][0]);

    return 0;
}

int max(int a, int b) 
{
    return a<b?b:a;
}
