#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 1010001000
#define min(a, b) a>b?b:a
#define max(a, b) a>b?a:b

typedef struct st{
    int be, af;
}st;

void init(int n);
int find(int x);
void unite(int x, int y);
int same(int x, int y);

int par[MAX_N], rank[MAX_N];
st data[121];
int jun[600];

int main(void)
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &data[i].be, &data[i].af);
    }


void init(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) {
        return ;
    }
    if (rank[x] < rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }
}

int same(int x, int y)
{
    //同じなら0, 違うならそれ以外
    return find(x) - find(y);
}

