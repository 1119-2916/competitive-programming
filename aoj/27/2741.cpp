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
// cmd

int table[51][51][101][2][2];

int calc(vi &yui, vi &kyoko, int n, int m, int st, int tu)
{
    bool funami = true, toshino = true;
    int score = 0;

    //cout << "call : " << n << " " << m << " " << st << " " << tu << endl;

    while (st--) {
        if (tu == 0) {
            if (yui[++n] == -1) {
                toshino = false;
            } else if (funami) {
                //cout << "yui : " << yui[n] << endl;
                score += yui[n];
            }
        } else {
            if (kyoko[++m] == -1) {
                funami = false;
            } else if (toshino) {
                //cout << "kyoko : " << kyoko[m] << endl;
                score -= kyoko[m];
            }
        }
        tu = !tu;
    }

    //cout << " " << score << endl;

    return score;
}

int solve(vi &yui, vi &kyoko, int n, int m, int st, int tu, int pa)
{
    if (table[n][m][st][tu][pa] != INF) {
        return table[n][m][st][tu][pa];
    }

    if (tu == 0) {
        int pass_score;
        if (pa == 1) {
            pass_score = 0;
        } else if (pa == 0 && st) {
            pass_score = calc(yui, kyoko, n, m, st, !tu) + 
                solve(yui, kyoko, n, m, 0, !tu, 0);
        } else if (pa == 0 && st == 0) {
            pass_score = solve(yui, kyoko, n, m, 0, !tu, 1);
        }
        int put_score;
        if (n) {
            put_score = solve(yui, kyoko, n-1, m, st+1, !tu, 0);
        } else {
            return table[n][m][st][tu][pa] = pass_score;
        }
        return table[n][m][st][tu][pa] = max(pass_score, put_score);
    } else {
        int pass_score;
        if (pa == 1) {
            pass_score = 0;
        } else if (pa == 0 && st) {
            pass_score = calc(yui, kyoko, n, m, st, !tu) + 
                solve(yui, kyoko, n, m, 0, !tu, 0);
        } else if (pa == 0 && st == 0) {
            pass_score = solve(yui, kyoko, n, m, 0, !tu, 1);
        }
        int put_score;
        if (m) {
            put_score = solve(yui, kyoko, n, m-1, st+1, !tu, 0);
        } else {
            return table[n][m][st][tu][pa] = pass_score;
        }
        return table[n][m][st][tu][pa] = min(pass_score, put_score);
    }
    puts("worning"); return -INF;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vector<int> yui(n+1);
    for (int i = n; i > 0; i--) {
        cin >> yui[i];
    }
    //Rep(i, n+1) cout << yui[i] << " "; cout << endl;

    vector<int> kyoko(m+1);
    for (int i = m; i > 0; i--) {
        cin >> kyoko[i];
    }
    //Rep(i, m+1) cout << kyoko[i] << " "; cout << endl;

    rep(i, 51) rep(j, 51) rep(k, 101) rep(ii, 2) rep(jj, 2)
        table[i][j][k][ii][jj] = INF;
    
    cout << solve(yui, kyoko, n, m, 0, 0, 0) << endl;
    // a, b, stack, turn(0, 1), pass

    return 0;
}
