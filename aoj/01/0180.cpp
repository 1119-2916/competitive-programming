#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++) 
#define INF 1010001000

typedef pair<int, int> i_i;
typedef struct Edge{ int fr, to, co; } Edge;

int n, m;
int par[101], rank[101];

void init(int n);
int find(int x);
void unite(int x, int y);
bool same(int x, int y);
int kruskal(Edge e[]);
bool cmp(const Edge &e1, const Edge &e2);

int main()
{
    while (cin >> n >> m, (n|m)) {
        Edge e[m];
        loop(i, m) {
            cin >> e[i].fr >> e[i].to >> e[i].co;
        }
        cout << kruskal(e) << endl;
    }
    return 0;
}

int kruskal(Edge e[])
{
    sort(e, &e[m], cmp);
    int ans = 0;
    init(n);
    loop(i, m) {
        if (!same(e[i].fr, e[i].to)) {
            ans += e[i].co;
            unite(e[i].fr, e[i].to);
        }
    }
    return ans;
}

void init(int n)
{
    loop(i, n) {
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

bool same(int x, int y)
{
    return find(x) == find(y);
}
                
bool cmp(const Edge &e1, const Edge &e2)
{
    return e1.co < e2.co;
}

