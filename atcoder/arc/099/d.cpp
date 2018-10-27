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

int ketawa(int a)
{
    int ret = 0;
    while (a) {
        ret += a % 10;
        a /= 10;
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);

    set<int> funami;
    Rep(i, 10) funami.insert(i);

    int q = 9;
    Rep(i, 16) {
        int a = i * 10;
        if (i > 10) {
            a -= 10;
        }
        Rep(j, a) {
            funami.insert(j * pow(10, i) + q);
        }
        q *= 10; q += 9;
    }

    int cnt = 0;
    for (auto i : funami) {
        cout << i << endl;
        cnt++;
        if (cnt == n) break;
    }

    return 0;
}
