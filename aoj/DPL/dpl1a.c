#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF_P 1100000000
#define INF_M -1100000000
#define MAX(a,b) a<b?b:a
#define MIN(a,b) a>b?b:a

int n, m;
int coin[20], dp[50001];

int main(void) 
{
    int i, j;
    scanf("%d %d",&m, &n);
    for (i = 0; i < n; i++) {
        scanf("%d",&coin[i]);
    }
    
    for (i = 1; i <= m; i++) {
        dp[i] = INF_P;
    }

    for (i = 0; i < n; i++) {
        for (j = coin[i]; j <= m; j++) {
            dp[j] = MIN(dp[j],dp[j-coin[i]]+1);
        }
    }

    printf("%d\n",dp[m]);

    return 0;
}



