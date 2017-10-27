#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define INF 1010001000

typedef pair<int, int> i_i;
typedef struct data{int pos, tick, cost;}data;

int dp(vector<vector<i_i > > &g);

int c, n, m, s, d;

int main(void)
{
    while (cin >> c >> n >> m >> s >> d, c) {
        n++;
        vector<vector<i_i > > g(n);
        loop(i, m) {
            int a, b, f;
            cin >> a >> b >> f;
            g[a].push_back(i_i(f, b));
            g[b].push_back(i_i(f, a));
        }
        cout << dp(g) << endl;
    }
    return 0;
}

int dp(vector<vector<i_i > > &g)
{
    vector<vector<int> > table(c+1, vector<int>(n, INF));
    queue<data> a;
    data dt = {s, c, 0};
    a.push(dt);
    while (!a.empty()) {
        data tmp = a.front(); a.pop();
        for (i_i i : g[tmp.pos]) {
            if (table[tmp.tick][i.second] > tmp.cost + i.first) {
                table[tmp.tick][i.second] = tmp.cost + i.first;
                dt.pos = i.second; dt.tick = tmp.tick; 
                dt.cost = tmp.cost + i.first;
                a.push(dt);
            }
            if (tmp.tick && 
                    table[tmp.tick-1][i.second] > tmp.cost + i.first / 2) {
                table[tmp.tick-1][i.second] = tmp.cost + i.first / 2;
                dt.pos = i.second; dt.tick = tmp.tick-1; 
                dt.cost = tmp.cost + i.first / 2;
                a.push(dt);
            }
        }
    }
    int ret = INF;
    for (int i = 0; i < c+1; i++) {
        ret = min(ret, table[i][d]);
    }
    return ret;
}
    

