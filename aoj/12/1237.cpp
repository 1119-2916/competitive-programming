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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);

//int dxy[5] = {0, 1, 0, -1, 0};
// assign

vi num, ans;
int n, ans_max;
bool rejected;
string input;

void solve(string data);

signed main()
{
    while (cin >> n >> input, n) {
        ans_max = -1;
        solve(input);
        if (rejected) {
            cout << "rejected" << endl;
        } else if (ans_max == -1 ) {
            cout << "error" << endl;
        } else {
            cout << ans_max;
            for (int i : ans) {
                cout << " " << i;
            }
            cout << endl;
        }
    }
    return 0;
}

void solve(string data)
{
    int a = 0;
    if (!data.size()) {
        int tmp = 0;
        for (int i : num) {
            tmp += i;
        }
        if (tmp > ans_max && tmp <= n) {
            rejected = false;
            ans_max = tmp;
            ans = num;
        } else if (tmp == ans_max) {
            rejected = true;
        }
        return ;
    }
    rep(i, data.length()) {
        a *= 10;
        a += data[i] - '0';
        num.eb(a);
        solve(&data[i+1]);
        num.pop_back();
    }
}
