#include <stdio.h>
#include <stdlib.h>
#define INF 1010001000
#define MAX_V 100001
#define MAX_E 1000000
#define min(a, b) a<b?a:b

typedef struct edge {
    int from, to, cost;
}edge;

int par[MAX_V], rank[MAX_V];

void init(int n);
int find(int x);
void unite(int x, int y);
int same(int x, int y);
int cmp(const void *a, const void *b);
int kruskal(void);

edge input[MAX_E];
int V, E;


int main(void)
{
    int i, j, s, t, d;
    int h, w;
    scanf("%d %d", &w, &h);
    for (i = 0; i < w; i++) {
        scanf("%d", &a);
    }
    scanf("%d %d", &V, &E);
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &input[i].from, &input[i].to, &input[i].cost);
    }
    printf("%d\n", kruskal());
    return 0;
}


int kruskal(void)
{
    edge e;
    int i, res = 0;
    init(V);
    qsort(input, E, sizeof(edge), cmp);
    for (i = 0; i < E; i++) {
        e = input[i];
        if (same(e.from, e.to)) {
            unite(e.from, e.to);
            res += e.cost;
        }
    }
    return res;
}

int cmp(const void *a, const void *b)
{
    edge temp1 = *(edge *) a;
    edge temp2 = *(edge *) b;
    return temp1.cost - temp2.cost;
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
