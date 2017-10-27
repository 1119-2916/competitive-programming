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
#define Edge pair< int, i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dij geo2

int fact(int a)
{
    int ret = 1;
    Rep(i, a+1) {
        ret *= i;
        ret %= MOD;
    }
    return ret;
}

signed main()
{
    int2(a, b);
    if (abs(a - b) > 1) {
        cout << 0 << endl;
        return 0;
    }

    if (a != b) {
        cout << (fact(a) * fact(b)) % MOD << endl;
    } else {
        cout << (2 * (fact(a) * fact(b))) % MOD << endl;
    }

    return 0;
}
