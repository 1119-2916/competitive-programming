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
    int i, j, k, l;
    cin >> i >> j >> k >> l;

    bool fl = false;
    rep(n, 10) {
        if (i == n) {
            continue;
        } else if (data[i][j][k][l] == data[n][j][k][l]) {
            fl = true;
        } else {
            cout << n << j << k << l << data[n][j][k][l]
                << endl;
        }
    }
    rep(n, 10) {
        if (j == n) {
            continue;
        } else if (data[i][j][k][l] == data[i][n][k][l]) {
            fl = true;
        } else {
            cout << i << n << k << l << data[i][n][k][l]
                << endl;
        }

    }
    rep(n, 10) {
        if (k == n) {
            continue;
        } else if (data[i][j][k][l] == data[i][j][n][l]) {
            fl = true;
        } else {
            cout << i << j << n << l << data[i][j][n][l]
                << endl;
        }

    }
    rep(n, 10) {
        if (l == n) {
            continue;
        } else if (data[i][j][k][l] == data[i][j][k][n]) {
            fl = true;
        } else {
            cout << i << j << k << n << data[i][j][k][n]
                << endl;
        }

    }

    if (data[i][j][k][l] == data[j][i][k][l] && i != j) {
        fl = true;
    } else {
        cout << j << i << k <<l<< data[j][i][k][l] << endl;
    }

    if (data[i][j][k][l] == data[i][k][j][l] && j != k) {
        fl = true;
    } else {
        cout << i << k << j << l << data[i][k][j][l]
            << endl;
    }

    if (data[i][j][k][l] == data[i][j][l][k] && k != l) {
        fl = true;
    } else {
        cout << i << j << l <<k<< data[i][j][l][k] << endl;
    }


    if (l == data[i][j][k][data[i][j][k][l]] && 
            l != data[i][j][k][l]) {
        fl = true;
    } else {
        cout << i << j << k <<data[i][j][k][data[i][j][k][l]]<< l << endl;
    }


    if (fl) {
        ret++;
    }
    cout << ret << endl;

    return 0;
}

