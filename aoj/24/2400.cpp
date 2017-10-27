#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

string ac = "CORRECT";
string wa = "WRONG";

typedef pair<int, pair<int, int> > Team;

int main()
{
    int t, p, r;
    while (cin >> t >> p >> r, t) {
        vector<Team> team(t);
        vector<vector<int> > solve(t, vector<int>(p, 0));
        rep(i, t) {
            team[i].second.second = i+1;
        }
        rep(i, r) {
            int a, b, c;
            string d;
            cin >> a >> b >> c >> d;
            if (ac == d) {
                if (solve[a-1][b-1] != -1) {
                    team[a-1].second.first += 
                        solve[a-1][b-1] * 1200 + c;
                    team[a-1].first--;
                    solve[a-1][b-1] = -1;
                }
            } else {
                if (solve[a-1][b-1] != -1) {
                    solve[a-1][b-1]++;
                }
            }
        }
        sort(team.begin(), team.end());
        rep(i, t) {
            cout << team[i].second.second << " " << -team[i].first << " "
                << team[i].second.first << endl;
        }
    }
    return 0;
}
