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

int n;
int data[300];
int dp[300][301]; // hankai
int score[300][301];

int solve(int st, int en)
{
    //cout << "call : " << st << " " << en << endl;;
    if ( dp[st][en] ) {
        //cout << " ret1 : 0" << endl;
        return score[st][en] = dp[st][en] = 0;
    }
    if ( score[st][en] ) {
        //cout << " ret2 : " << score[st][en] << endl;
        return score[st][en];
    }
    if (en - st < 2) {
        //cout << " ret3 : " << en - st << endl;
        return score[st][en] = en - st;
    }
    int ret = en - st;
    for (int i = st+2; i < en; i++) {
        if (dp[st][i]) {
            ret = min(solve(i, en), ret);
        }
    }
    return score[st][en] = min(ret, 1+solve(st+1, en));
    //score[st][en] = min(ret, 1+solve(st+1, en));
    //cout << score[st][en] << endl;
    //return score[st][en];
}

void make(int st, int en)
{
    //cout << "call : " << st << " " << en << endl;
    if (en - st < 2) return;

    if (0 <= st - 1 && en + 1 <= n && abs(data[st-1]-data[en]) < 2)
        dp[st-1][en+1] = 1;

    for (int i = max(0LL, st - (en - st)); i < st; i++)
        if (dp[i][st]) dp[i][en] = 1;

    for (int i = en+1; i < min(n+1, en + (en - st)); i++)
        if (dp[en][i]) dp[st][i] = 1;

}

signed main() 
{ 
    std::ios::sync_with_stdio(false); 
    std::cin.tie(0); 

    cin >> n;
    while ( n ) {
        memset(data, 0, sizeof(data));
        memset(dp, 0, sizeof(dp));
        memset(score, 0, sizeof(score));
        rep(i, n) cin >> data[i];

        rep(i, n-1) if (abs(data[i] - data[i+1]) < 2) dp[i][i+2] = 1;
        /*
        rep(i, n) {
            Rep(j, n+1) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << "============" << endl;
        */

        for (int i = 2; i < n; i++) {
            for (int st = 0; st < n - i + 1; st++) {
                int en = st + i;
                if (dp[st][en]) make(st, en);
            }
        }

        /*
        rep(i, n) {
            Rep(j, n+1) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */

        cout << n - solve(0, n) <<endl;
        cin >> n;
    }

    return 0; 
}
