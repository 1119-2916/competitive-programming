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
typedef pair<int, pair<int, int> > Team;
typedef pair<int, pair<int, pair<int, int> > > input;

int m, t, p, r;

int main()
{
    while (cin >> m >> t >> p >> r, m) {
        vector<Team > team(t);
        vector<vector<int> > check(t, vector<int>(p, 0));
        vector<input > data(r);
        rep(i, t) {
            team[i].second.second = i+1;
            team[i].first = 0;
            team[i].second.first = 0;
        }
        rep(i, r) {
            cin >> data[i].first >> data[i].second.second.second
                >> data[i].second.second.first 
                >> data[i].second.first;
            data[i].second.second.second--;
            data[i].second.second.first--;
            data[i].second.first *= -1;
        }
        sort(data.begin(), data.end());
        rep(i, r) {
            int a = data[i].first, b = data[i].second.second.second, 
                c = data[i].second.second.first, 
                d = data[i].second.first;
            if (d) {
                if (check[b][c] != -1) {
                    check[b][c]++;
                }
            } else {
                if (check[b][c] != -1) {
                    team[b].first++;
                    team[b].second.first 
                        -= data[i].first + check[b][c] * 20;
                    check[b][c] = -1;
                }
            }
        }
        sort(team.begin(), team.end(), greater<Team>());
        cout << team[0].second.second;
        for (int i = 1; i < t; i++) {
            if (team[i].first == team[i-1].first && 
                    team[i].second.first == team[i-1].second.first) {
                cout << "=" << team[i].second.second;
            } else {
                cout << "," << team[i].second.second;
            }
        }
        cout << endl;
    }

    return 0;
}
