#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF_P 1100000000
#define INF_M -1100000000
#define MAX(a,b) a<b?b:a
#define MIN(a,b) a>b?b:a

struct item{
    int weight;
    int value;
};

int n, w;
int dp[10001];
struct item goods[100];

int main(void) 
{
    int i, j, ans = -1;
    scanf("%d %d",&n, &w);

    for (i = 0; i < n; i++) {
        scanf("%d %d",&goods[i].value, &goods[i].weight);
    }

    for (i = 0; i < n; i++) {
        for (j = w-1; j > 0; j--) {
            if (dp[j] && j + goods[i].weight <= w) {
                dp[j+goods[i].weight] = 
                    MAX(dp[j+goods[i].weight],dp[j]+goods[i].value);
            }
        }
        dp[goods[i].weight] = 
                    MAX(dp[goods[i].weight],goods[i].value);
    }
    
    for (i = 0; i <= w; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }

    printf("%d\n",ans);
    return 0;
}

