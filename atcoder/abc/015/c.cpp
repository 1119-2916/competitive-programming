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
#define eb emplece_back
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

int n, k, ans;
int data[5][5];

void solve(int calc, int pos);

signed main()
{
    cin >> n >> k;
    rep(i, n) rep(j, k) cin >> data[i][j];
    ans = INF;
    solve(0, 0);
    cout << ( (ans) ? "Nothing" : "Found" ) << endl;
    return 0;
}


void solve(int calc, int pos)
{
    if (pos == n) {
        ans = min(ans, calc);
        return;
    }
    rep(i, k) {
        solve(calc ^ data[pos][i], pos+1);
    }
}

