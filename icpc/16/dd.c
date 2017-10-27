#include <stdio.h>
#define min(a, b) a>b?b:a
#define max(a, b) a>b?a:b
#define abs(a) a<0?-a:a

int dalma[300];
int n;
int dp[300][300];

int solve(int st, int en)
{
    int ans1, ans2, ans3;
    if (dp[st+1][en-1] == en-1-st-1) {
        if ((dalma[st] - dalma[en] <= 1) 
                && (dalma[en] - dalma[st] <= 1)) {
            dp[st][en] = en-st;
        }
    } else {
        solve(st+1, en-1);
    }





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

