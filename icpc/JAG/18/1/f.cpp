#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define int long long
#define fir first
#define sec second
#define MOD 1000000007

int pascal[10001][10001];

int solve(int a, int b, int m, int keta)
{
    if (!keta) return;

signed main(void)
{
    int t; cin >> t;
    while (t--) {
        int a, b, m;
        cin >> a >> b >> m;
        memset(pascal, 0, sizeof(pascal));
        pascal[0][0] = 1;
        int tmp = m, keta = 0;
        while (tmp > a) {
            tmp *= m;
            keta++;
        }
        for (int i = 0; i < m-1; i++) {
            for (int j = 0; j < m; j++) {
                pascal[i+1][j] += pascal[i][j];
                pascal[i+1][j] %= MOD;
                pascal[i+1][j+1] += pascal[i][j];
                pascal[i+1][j+1] %= MOD;
            }
        }
        cout << solve(a, b, m, keta) << endl;
    }
    return 0;
}
