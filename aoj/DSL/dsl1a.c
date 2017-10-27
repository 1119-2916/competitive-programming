#include <stdio.h>
#define MAX_N 10000

int par[MAX_N], rank[MAX_N];
int n, q;

void init(int n);
void unite(int a, int b);
int find(int x);

int main(void)
{
    int i;
    int com, a, b;

    scanf("%d %d",&n, &q);

    init(MAX_N);

    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&com, &a, &b);
        if (com) {
            if (find(a) == find(b)) {
                puts("1");
            } else {
                puts("0");
            }
        } else {
            unite(a, b);
        }
    }
    return 0;
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
        par[x] = find(par[x]);
        return par[x];
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

