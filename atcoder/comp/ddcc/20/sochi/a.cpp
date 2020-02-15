#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-10
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


int la, lb, lc, na, nb, nc, ne, ma, mb, mc, tc;

int nowTank;

int dripA(int millis = 120)
{
    nowTank = (millis / na) * na;
    return min(millis / na * 1000, ma);
}

int dripE(int millis = 120)
{
    return min(millis / ne * 1000, 60000);
}

void run(int a, int b, int c, int d,
        int e, int f, int g, int h,
        int i,
        int j, int k, int l, int m)
{
    cout << a << ","
         << b << ","
         << c << ","
         << d << ","
         << e << ","
         << f << ","
         << g << ","
         << h << ","
         << i << ","
         << j << ","
         << k << ","
         << l << ","
         << m << endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> la >> lb >> lc >> na >> nb >> nc >> ne >>
        ma >> mb >> mc >> tc;

    run(la, 500, 3000, 3000,
        900, 500, 3000, 3000,
        0,
        0, 0, 0, 0);

    run(la, 1, 60, 60,
        900, 1, 60, 60,
        0,
        dripA(), 0, 0, 0);
        //500, 0, 0, 0);

    run(90, 500, 3000, 3000,
        50, 500, 3000, 3000,
        0,
        0, 0, 0, 0);

    run(90, 1, 60, 60,
        50, 1, 60, 60,
        0,
        0, 0, 0, 60000);

    return 0;
}


