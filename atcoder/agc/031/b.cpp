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

int A, B;

int pdiff(int a, int b)
{
    int cnt = 0;
    while (a || b) {
        cnt += ((a % 2) == (b % 2) ? 0 : 1);
        a /= 2; b /= 2;
    }
    return cnt;
}

int out[2][8] = {
    {
    0, 1, 3, 2,
    2, 3, 1, 0,
    }, 
    {
    0, 1, 3, 2,
    2, 0, 1, 3,
    }
};

void solve(vi &ans, int n, int t)
{
    used(n, 0);
    if (t) {
        int first_keta;
        rep(i, n) {
            if (A^B & (1 << i) == 0) {
                used[i] = 1;
                first_keta = i;
                break;
            }
        }
        for (int i = 1; i < ans.size(); i += 4) {
            ans[i] += (1 << first_keta);
            ans[i+1] += (1 << first_keta);
        }
    }
    for (int i = 0; i < n; i += 2) {
        int keta1, keta2;
        rep(j, used.size()) {
            if (used[j] == 0) {
                keta1 = j;
                used[j] = 1;
                break;
            }
        }
        int sen = (A^B & (1 << keta1));
        rep(j, used.size()) {
            if (used[j] == 0 && 
                    A^B & (1 << j) == A^B & (1 << keta1)) {
                keta2 = j;
                used[j] = 1;
                break;
            }
        }
        int la = (out[sen][i] & 2) << keta1,
            lb = (out[sen][i] & 1) << keta2;

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    int2(a, b);
    A = a; B = b;
    vi ans(1 << n, 0);
    if (pdiff(a, b) % 2) {
        solve(n, n % 2);
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}


