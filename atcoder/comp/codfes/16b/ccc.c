#include <stdio.h>
int par[MAX_N], rank[MAX_N];

void init(int n);
int find(int x);
void unite(int x, int y);
int same(int x, int y);

int main(void)
{
    int w, h;
    scanf("%d %d", &w, &h);


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

