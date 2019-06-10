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

bool solve(string &st, int s, int t)
{
    vi dp(st.size(), 0);
    dp[s] = 1;
    for (int i = s; i < t; i++) {
        if (dp[i]) {
            if (in(i+1, 0, st.size()) && st[i+1] == '.') dp[i+1] = 1;
            if (in(i+2, 0, st.size()) && st[i+2] == '.') dp[i+2] = 1;
        }
    }
    //for (int i = s; i < t+1; i++) cout << dp[i] << " ";
    return dp[t];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(n, a, b);
    int2(c, d);
    a--; b--; c--; d--;
    string st;
    cin >> st;
    
    if (c > d) {
        for (int i = b; i <= d; i++) {
            if (in(i-1, 0, n) && in(i+1, 0, n)) {
                if (st[i-1] == '.' && st[i] == '.' && st[i+1] == '.') {
                    b = i;
                    if (solve(st, a, i-1)) {
                        a = i+1;
                    } else {
                        std::cout << "No" << std::endl;
                    }
                    if (solve(st, a, c) && solve(st, b, d)) {
                        std::cout << "Yes" << std::endl;
                    } else {
                        std::cout << "No" << std::endl;
                    }
                    return 0;
                }
            }
        }
        std::cout << "No" << std::endl;
        return 0;
    }

    if (solve(st, b, d) && solve(st, a, c)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
