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
#define eb emplace_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    vb used(n, false);
    rep(i, n) {
        if (data[i] == 2) {
            used[i] = true;
        }
    }

    int cnt = 0;
    vi yui(2, 0);
    rep(i, n) {
        if (data[i] == -1) {
            yui[0]++;
        } else if (data[i] == -2) {
            yui[1]++;
        }
    }

    if ((yui[0] + yui[1]) % 2 == 0) {
        cnt = 0;
        rep(i, n) {
            if (data[i] == -2) {
                cnt++;
                used[i] = true;
            }
        }
        if (cnt % 2) {
            rep(i, n) {
                if (data[i] == -1) {
                    used[i] = true;
                    break;
                }
            }
        }
    } else if (yui[1] % 2 == 0) {
        rep(i, n) {
            if (data[i] == -2) {
                cnt++;
                used[i] = true;
            }
        }
    } else if (yui[0] && yui[1]) {
        rep(i, n) {
            if (data[i] == -2) {
                cnt++;
                used[i] = true;
            }
        }
        if (cnt % 2) {
            rep(i, n) {
                if (data[i] == -1) {
                    used[i] = true;
                    break;
                }
            }
        }
    } else if (yui[1]) {
        rep(i, n) {
            if (data[i] == -2) {
                cnt++;
                used[i] = true;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (data[i] == -2) {
                used[i] = false;
                break;
            }
        }
    }

    cnt = 0;
    rep(i, n) cnt += used[i];

    cout << cnt << endl;
    rep(i, n) {
        if (used[i]) {
            cout << i+1 << endl;
        }
    }

    return 0;
}
