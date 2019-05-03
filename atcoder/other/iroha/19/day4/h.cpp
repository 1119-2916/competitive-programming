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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

bool check(vi &data)
{
    int n = data.size();
    rep(i, n) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (data[j] - data[i] == data[k] - data[j]) {
                    std::cout << data[i] << " " << data[j] << " " << data[k] << std::endl;
                    return false;
                }
            }
        }
    }
    return true;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);

    /*
    rep(j, n) {
        vector<int> data(n);
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }

        cout << check(data) << endl;
    }

    /*/
    vi out(n*n+1, 0);
    while (1) {
        vi used(n*n+1, 0), ans(n, 0);
        rep(i, out.size()) {
            used[i] = out[i];
        }
        rep(i, n) {
            int p = 0;
            Rep(j, used.size()) {
                if (!used[j]) {
                    p = j;
                    break;
                }
            }
            if (p == 0) {
                rep(j, i+1) cout << ans[j] << " "; cout << endl;
                return 0;
            }
            used[p] = 1;
            ans[i] = p;
            rep(j, i) {
                if (p + (p - ans[j]) < used.size()) 
                    used[p + (p - ans[j])] = 1;
            }
        }
        rep(i, ans.size()) {
            std::cout << ans[i] << " ";
            out[ans[i]] = 1;
        }
        cout << endl;
    }
    //*/

    return 0;
}
