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

int memo[5][200][32768];
 
int solve(int n, int i, int cnt);
void dp();

signed main()
{
    memset(memo[5][200], -1, 32768);
    Int(n);
    while (n) {
        cout << solve(n, 1, 0) << endl;
        cin >> n;
    }

    return 0;
}

int solve(int n, int i, int cnt)
{
    if (cnt > 4) {
        return 0;
    } else if (!n) {
        return 1;
    } else {
        int ans = 0;
        if (memo[cnt][i][n] != -1) {
            return memo[cnt][i][n];
        } else {
            while (i * i <= n) {
                ans += solve(n - i*i, i, cnt+1);
                i++;
            }
            memo[cnt][i][n] = ans;
            return ans;
        }
    }
}

