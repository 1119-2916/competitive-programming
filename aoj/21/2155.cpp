#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
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


int main()
{
    int n, m;
    while (cin >> n >> m, n) {
        vector<pair<int ,i_i > > data(m);
        vector<bool> infected(n, false);
        rep(i, m) {
            cin >> data[i].first >> data[i].second.first
                >> data[i].second.second;
            data[i].second.first--;
            data[i].second.second--;
        }
        sort(data.begin(), data.end());
        infected[0] = true;
        rep(i, m) {
            infected[data[i].second.second] = 
                (infected[data[i].second.second] || 
                 infected[data[i].second.first]);
        }
        int ret = 0;
        rep(i, n) {
            if (infected[i]) {
                ret++;
            }
        }
        cout << ret << endl;
    }
    return 0;
}
