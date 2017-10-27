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
// assign

signed main()
{
    vvi table(10, vi(10));

    rep(i, 10) {
        rep(j, 10) {
            cin >> table[i][j];
        }
    }

    int data[10][10][10][10];

    rep(i, 10) {
        rep(j, 10) {
            rep(k, 10) {
                rep(l, 10) {
                    data[i][j][k][l] = 
                        table[table[table[table[0][i]][j]][k]][l];
                }
            }
        }
    }
    int ret = 0;
    rep(i, 10) {
        rep(j, 10) {
            rep(k, 10) {
                rep(l, 10) {
                    bool fl = false;
                    rep(n, 10) {
                        if (i == n) {
                            continue;
                        } else if (!table[data[n][j][k][l]]
                                [data[i][j][k][l]]) {
                            fl = true;
                        }
                    }
                    rep(n, 10) {
                        if (j == n) {
                            continue;
                        } else if (!table[data[i][n][k][l]]
                                [data[i][j][k][l]]) {
                            fl = true;
                        }
                    }
                    rep(n, 10) {
                        if (k == n) {
                            continue;
                        } else if (!table[data[i][j][n][l]]
                                [data[i][j][k][l]]) {
                            fl = true;
                        }
                    }
                    rep(n, 10) {
                        if (l == n) {
                            continue;
                        } else if (!table[data[i][j][k][n]]
                                [data[i][j][k][l]]) {
                            fl = true;
                        }
                    }
                    rep(n, 10) {
                        if (data[i][j][k][l] == n) {
                            continue;
                        } else if (!table[data[i][j][k][l]][n]) {
                            fl = true;
                        }
                    }

                    if (!table[data[j][i][k][l]][data[i][j][k][l]]
                            && i != j) {
                        fl = true;
                    }

                    if (!table[data[i][k][j][l]][data[i][j][k][l]]
                            && k != j) {
                        fl = true;
                    }

                    if (!table[data[i][j][l][k]][data[i][j][k][l]]
                            && k != l) {
                        fl = true;
                    }
                    if (!table[data[i][j][k][data[i][j][k][l]]][l]
                           && l != data[i][j][k][l]) {
                        fl = true;
                    }

                    if (fl) {
                        ret++;
                    }
                }
            }
        }
    }
    cout << ret << endl;

    return 0;
}

