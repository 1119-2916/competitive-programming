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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

int n, m, q;
int table[1000][40];

void print_table(int a, int b);

signed main()
{
    while ( cin >> n >> m >> q, n ) {
        string sw1, sw2, state1, state2;
        rep(i, n) { sw1.pb('0'); }
        rep(i, m) { state1.pb('0'); }
        memset(table, 0, sizeof(table));

        rep(loop, q) {
            cin >> sw2 >> state2;
            vi sws, swn;
            rep(i, sw2.length()) {
                if (sw2[i] == '1') {
                    sws.pb(i);
                } else {
                    swn.pb(i);
                }
            }
            rep(i, state2.length()) {
                if (state1[i] != state2[i]) {
                    for (int pos : sws) {
                        if (table[i][pos] != -1) {
                            table[i][pos] = 1;
                        }
                    }
                    for (int pos : swn) {
                        table[i][pos] = -1;
                    }
                } else {
                    for (int pos : sws) {
                        table[i][pos] = -1;
                    }
                }
            }
            sw1 = sw2;
            state1 = state2;
            //print_table(n, m);
        }
        rep(i, m) {
            int ans = -1;
            rep(j, n) {
                if (table[i][j] != -1 && ans == -1) {
                    ans = j;
                } else if (table[i][j] != -1) {
                    ans = -2;
                }
            }
            if (0 <= ans && ans <= 9) {
                cout << ans;
            } else if (10 <= ans) {
                printf("%c", 'A' + (ans - 10));
            } else {
                cout << '?';
            }
        }
        cout << endl;
    }

    return 0;
}

void print_table(int a, int b)
{
    rep(i, a) {
        rep(j, b) {
            printf("%5lld", table[j][i]);
        }
        cout << endl;
    }
}

