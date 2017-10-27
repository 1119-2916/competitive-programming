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
 
signed main()
{
    string s;
    cin >> s;
    vp data(s.size(), i_i(-INF, 0));
    rep(i, s.size()) data[i].second = i;

    int sum = 0, n = 0;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '+') {
            sum++;
        } else if (s[i] == '-') {
            sum--;
        } else {
            data[i].first = sum;
            n++;
        }
    }
    sort(all(data));
    reverse(all(data));
    rep(i, n/2) {
        s[data[i].second] = '>';
    }
    rep(i, n/2) {
        s[data[i+n/2].second] = '<';
    }

    int ans = 0, pos = 0;
    rep(i, s.size()) {
        if (s[i] == '+') {
            ans += pos;
        } else if (s[i] == '-') {
            ans -= pos;
        } else if (s[i] == '>') {
            pos++;
        } else {
            pos--;
        }
    }
    cout << ans << endl;





    return 0;
}

