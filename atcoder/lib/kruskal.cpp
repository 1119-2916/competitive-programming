#include <iostream>
#include <algorithm>
using namespace std;

struct edge{int u, v, cost;};

#define MAX_N 100001
#define MAX_E 100001

int par[MAX_N];
int rank[MAX_N];
edge es[MAX_E];
int V, E;

void init(int n);
int find(int x);
void unite(int x, int y);
bool same(int x, int y);
bool comp(const edge& e1, const edge& e2);

int kruskal()
{
    sort(es, es + E, comp);
    init(V);
    int res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

void init(int n) 
{
    for (int i = 0; i < n; i++) {
        par[i] =  i;
        rank[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) {
        retuen x;
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

bool same(int x, int y) 
{
    return find(x) == find(y);
}

bool comp(const edge& e1, const edge& e2)
{
    return e1.cost < e2.cost;
}
