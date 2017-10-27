#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define INF 1010001000
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef pair<int, int> i_i;
typedef long long int llong;
typedef pair<llong, llong> ll_ll;
typedef struct edge {int f, t;}Edge;

void dij(int st, int en);

vector<vector<int> > edge(101, vector<int>(101, INF));
vector<vector<bool> > used(101, vector<bool>(101, false));
int n, m;

int main()
{
    cin >> n >> m;
    int ret = 0;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        if (edge[a][b] == INF) {
            edge[a][b] = c;
            edge[b][a] = c;
        } else {
            ret++;
            edge[a][b] = min(edge[a][b], c);
            edge[b][a] = min(edge[b][a], c);
        }
    }
    rep(i, n) {
        for (int j = i+1; j < n; j++) {
            dij(i+1, j+1);
        }
    }
    rep(i, n) {
        for (int j = i+1; j < n; j++) {
            if (edge[i+1][j+1] != INF && !used[i+1][j+1]) {
                ret++;
            }
        }
    }
    cout << ret << endl;
    return 0;
}

void dij(int st, int en)
{
    vector<int> ans(101, INF);
    vector<int> prev(101, 0);
    priority_queue<i_i, vector<i_i >, greater<i_i > > pq;
    pq.push(i_i(0, st));
    ans[st] = 0;
    while (!pq.empty()) {
        i_i p = pq.top(); pq.pop();
        int u = p.second;
        if (ans[u] < p.first) {
            continue;
        }
        rep(i, n) {
            if (ans[i+1] > ans[u] + edge[u][i+1]) {
                ans[i+1] = ans[u] + edge[u][i+1];
                pq.push(i_i(ans[i+1], i+1));
                prev[i+1] = u;
            }
        }
    }
    int next = en;
    while (1) {
        if (next == st) {
            break;
        } else {
            used[prev[next]][next] = true;
            used[next][prev[next]] = true;
            next = prev[next];
        }
    }
}

