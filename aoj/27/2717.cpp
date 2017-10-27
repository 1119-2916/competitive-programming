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
    int n, m;
    cin >> n >> m;
    vector< string > board(m);
    i_i all = i_i(0, 0);
    i_i sum = all;

    rep(i, m) {
        cin >> board[i];
    }

    vector< i_i > cnt(n, i_i(0, 0));
    rep(i, n) {
        rep(j, m) {
            if (board[j][i] == 'W') {
                cnt[i].first++;
                all.first++;
            } else {
                cnt[i].second++;
                all.second++;
            }
        }
    }
//    cout << all.first << " " << all.second << endl;

    int min = all.first, ans = -1;
    rep(i, n) {
        sum.first += cnt[i].first;
        sum.second += cnt[i].second;
        all.first -= cnt[i].first;
        all.second -= cnt[i].second;
        //cout << sum.first << sum.second << endl;
        //cout << all.first << all.second << endl;
        int tmp = sum.second + all.first;
        //cout << tmp << endl;
        if (min > tmp) {
            min = tmp;
            ans = i;
        }
    }

    cout << ans+1 << " " << ans+2 << endl;

    return 0;
}

