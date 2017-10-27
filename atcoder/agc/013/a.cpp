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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

int n;
vi data;

signed main()
{
    cin >> n;
    data.assign(n, 0);
    rep(i, n) {
        cin >> data[i];
    }

    int ans = 0, state = 0, num = data[0];
    Rep(i, n) {
        if (state == 1) {
            if (num > data[i]) {
                state = 0;
                ans++;
            }
        } else if (state == -1) {
            if (num < data[i]) {
                state = 0;
                ans++;
            }
        } else {
            if (num < data[i]) {
                state = 1; // inc
            } else if (num > data[i]) {
                state = -1;
            }
        }
        num = data[i];
    }
    cout << ans +1 << endl;


    return 0;
}

