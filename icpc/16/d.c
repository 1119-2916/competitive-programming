#include <stdio.h>
#define min(a, b) a>b?b:a
#define max(a, b) a>b?a:b
#define abs(a) a<0?-a:a

int dalma[300];
int n;
int dp[300][300];

int main(void)
{
    int i, j, k, ans;
    scanf("%d", &n);
    while (n) {
        for (i = 0; i < n; i++) {
            scanf("%d", &dalma[i]);
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        for (i = 0; i < n-1; i++) {
            dp[i][i+1] = ((dalma[i]-dalma[i+1] <= 1
                         && dalma[i+1]-dalma[i] <= 1)?1:0) * 2;
            printf("%d ", dp[i][i+1]);
        }
        for (i = 2; i < n; i += 2) {
            for (j = 0; j < n - i - 1; j++) {
                for (k = j + 1; k < j + i + 1; k++) {
                    dp[j][j+i+1] = max(dp[j][j+i+1], 
                            dp[j+1][k] + dp[k+1][j+i+1]);
                }
                dp[j][j+i+1] += ((dalma[j]-dalma[j+i+1] <= 1
                         && dalma[j+i+1]-dalma[j] <= 1)?1:0) * 2;
                for (k = j; k < j + i + 1; k++) {
                    dp[j][j+i+1] = max(dp[j][j+i+1], 
                            dp[j][k] + dp[k+1][j+i+1]);
                }
            }
        }
        ans = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        printf("%d\n", ans);
        scanf("%d", &n);
    }
    return 0;
}
        
