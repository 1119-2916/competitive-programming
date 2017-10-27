#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);

//int dxy[5] = {0, 1, 0, -1, 0};
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
// assign

string comp(string a, string b);

signed main()
{
    int n, m;
    while (cin >> n >> m, n) {
        vector<string> donut(n);
        rep(i, n) {
            cin >> donut[i];
        }
        set<string> can;
        string ans = "z";
        rep(i, n) {
            rep(j, m) {
                rep(k, 8) {
                    vvb used(n, vb(m, false));
                    string spell;
                    int x = i, y = j;
                    while (!used[x][y]) {
                        spell.pb(donut[x][y]);
                        used[x][y] = true;
                        if (can.find(spell) != can.end()) {
                            ans = comp(ans, spell);
                        } else {
                            can.insert(spell);
                        }
                        x = (x + dx[k] + n) % n; y = (y + dy[k] + m) % m;
                    }
                }
            }
        }
        cout << ((ans.length() > 1) ? ans : "0") << endl;
    }
    return 0;
}

string comp(string a, string b)
{
    if (a.length() < b.length()) {
        return b;
    } else if (a.length() > b.length()) {
        return a;
    } else {
        rep(i, a.length()) {
            if (a[i] < b[i]) {
                return a;
            } else if (a[i] > b[i]) {
                return b;
            }
        }
    }
    return a;
}

