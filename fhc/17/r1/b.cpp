#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define INF 1010001000
#define LINF 1001000100010001000
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef pair<int, int> i_i;
typedef long long int llong;
typedef pair<llong, llong> ll_ll;
typedef struct edge {int f, t;}Edge;


int main()
{
    int t;
    cin >> t;
    rep(state, t) {
        cout << "Case #" << state + 1 << ": ";
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<llong> > graph(n, vector<llong>(n, LINF));
        rep(i, n) {
            graph[i][i] = 0;
        }
        rep(i, m) {
            llong a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            graph[a][b] = min(graph[a][b], c);
            graph[b][a] = min(graph[b][a], c);
        }
        rep(kk, n) {
            rep(i, n) {
                rep(j, n) {
                    graph[i][j] = min(graph[i][j], 
                            graph[i][kk] + graph[kk][j]);
                }
            }
        }

        vector<vector<llong> > dps(2, vector<llong>(k, LINF));
        vector<vector<llong> > dpg(2, vector<llong>(k, LINF));
        vector<i_i> query(k);

        rep(i, k) {
            cin >> query[i].first >> query[i].second;
            query[i].first--; query[i].second--;
        }
        // s1, s2, g0, g1
        dps[0][0] = graph[0][query[0].first];

        for (int i = 0; i < k; i++) {

            dpg[0][i] = min(dpg[0][i], 
                    dps[0][i] + graph[query[i].first][query[i].second]);

            if (i+1 < k) {

            dps[1][i+1] = min(dps[1][i+1], 
                    dps[0][i] + graph[query[i].first][query[i+1].first]);

            dps[0][i+1] = min(dps[0][i+1], 
                    dpg[0][i] + graph[query[i].second][query[i+1].first]);

            dpg[1][i] = min(dpg[1][i], 
                    dps[1][i+1] + graph[query[i+1].first][query[i].second]);

            dpg[0][i+1] = min(dpg[0][i+1], 
                    dpg[1][i] + graph[query[i].second][query[i+1].second]);

            if (i+2 < k) {

            dps[1][i+2] = min(dps[1][i+2], 
                    dpg[1][i] + graph[query[i].second][query[i+2].first]);

            }

            }

        }

        /*
        rep(i, k) {
            cout << dps[0][i] << " ";
        } cout << endl;
        rep(i, k) {
            cout << dps[1][i] << " ";
        } cout << endl;
        rep(i, k) {
            cout << dpg[0][i] << " ";
        } cout << endl;
        rep(i, k) {
            cout << dpg[1][i] << " ";
        } cout << endl;
        */


        if (dpg[0][k-1] < LINF) {
            cout << dpg[0][k-1] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
