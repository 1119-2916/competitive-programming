#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 1010001000
#define min(a, b) a>b?b:a
#define max(a, b) a>b?a:b

int usa[16];
int graph[16][16];
int n, m;

int dfs(int st, int value)
{
    int i;
    for (i = 0; i < n; i++) {
        if (graph[st][i]) {
            usa[i] = max(usa[i], value +1);
            dfs(i, value+1);
        }
    }
}

int main(void)
{
    int i, a, b;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a-1][b-1] = 1;
    }
    for (i = 0; i < n; i++) {
        dfs(i, 0);
    }
    for (i = 0; i < n; i++) {
        printf("%d\n", usa[i]);
    }
    return 0;
}



    


