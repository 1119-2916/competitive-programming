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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
vi pat;
int n, m;
 
int solve(vi data, int st);

signed main()
{
    cin >> n >> m;
    vi input(n), fir(n), sec(n);
    int one = 0, zero = 0;
    rep(i, n) {
        cin >> input[i];
        fir[i] = sec[i] = input[i];
    }
    rep(i, m) {
        int tmp;
        cin >> tmp;
        pat.pb(tmp);
    }

    cout << min(solve(fir, 0), solve(sec, 1)) << endl;

    return 0;
}

int solve(vi data, int st)
{
    int pos = 0, ret = 0;
    rep(i, m) {
        int cnt = 0;
        while (cnt != pat[i]) {
            if (data[pos] == st) {
                cnt++;
                pos++;
            } else {
                bool fl = false;
                for (int j = pos; j + 1 < n; j++) {
                    if (data[j+1] == st) {
                        int tmp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = tmp;
                        ret++;
                        fl = true;
                        break;
                    }
                }
                if (!fl) {
                    return INF;
                }
            }
        }
        st = (st + 1) % 2;
    }
    return ret;
}

