#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct edge{int u, v, cost;};

#define MAX_N 100001
#define MAX_E 100001

int par[MAX_N];
int rank[MAX_N];
edge es[MAX_E];
int V, E;

int kruskal();
void init(int n);
int find(int x);
void unite(int x, int y);
bool same(int x, int y);
bool comp(const edge& e1, const edge& e2);

int main()
{
    cin >> V;
    while (V) {
        cin >> E;
        for (int i = 0; i < E; i++) {
            scanf("%d,%d,%d", &es[i].u, &es[i].v, &es[i].cost);
        }
        cout << kruskal() << endl;
        cin >> V;
    }

    return 0;
}


int kruskal()
{
    sort(es, es + E, comp);
    init(V);
    int res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            if (e.cost < 100) {
                res += 1;
            } else {
                res += (e.cost-1) / 100;
            }
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

bool same(int x, int y) 
{
    return find(x) == find(y);
}

bool comp(const edge& e1, const edge& e2)
{
    return e1.cost < e2.cost;
}
