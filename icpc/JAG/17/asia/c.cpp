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

int prime[1001000];

void table()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < 1001000; i++) {
        if (!prime[i]) {
            for (int j = 2; i * j < 1001000; j++) {
                prime[i*j] = 1;
            }
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    table();
    int2(a, b);

    vp ans(b-a+1);
    rep(i, ans.size()) {
        ans[i].fir = i + a;
        ans[i].sec = 0;
    }

    for (int i = 0; i < 1001000; i++) {
        if (!prime[i]) {
            int hoge = (i - (a % i)) % i;
            for (int j = hoge; j < ans.size(); j += i) {
                while (ans[j].fir % i == 0) {
                    ans[j].fir /= i;
                    ans[j].sec++;
                }
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].fir != 1) ans[i].sec++;
        ret += !prime[ans[i].sec];
    }

    std::cout << ret << std::endl;

    return 0;
}
