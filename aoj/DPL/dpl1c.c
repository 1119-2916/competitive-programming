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

int max(int a, int b);

int n, w;
int dp[101][10001];
struct item goods[101];

int main(void)
{
    int i, j, tmp;

    scanf("%d %d",&n, &w);

    for (i = 1; i <= n; i++) {
        scanf("%d %d",&goods[i].value, &goods[i].weight);
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= w; j++) {
            if (goods[i].weight <= j) {
                dp[i][j] = max(dp[i-1][j],
                        max(dp[i][j-goods[i].weight]+goods[i].value,
                            dp[i-1][j-goods[i].weight]+goods[i].value));
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    tmp = -1;
    for (i = 0; i <= w; i++) {
        if (tmp < dp[n][i]);
        tmp = dp[n][i];
    }
    printf("%d\n",tmp);
    return 0;
}

int max(int a, int b) 
{
    if (a < b) {
        return b;
    } else {
        return a;
    }
}

