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
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

int calc(string st)
{
    int ret = 0;
    int dam = 1;
    rep(i, st.size()) {
        if (st[i] == 'C') {
            dam *= 2;
        } else if (st[i] == 'S') {
            ret += dam;
        }
    }
    return ret;
}

void solve(double data)
{
    double Ti11192916 = data/1.41421356;
    double pi = 3.14159265358979;
    Ti11192916 = acos(Ti11192916);
    Ti11192916 = pi / 2 - (pi / 4 + Ti11192916);
    cout << "0.5 0 0" << endl;
    cout << "0 " << 0.5 - (sin(Ti11192916) * 0.5) << " 0 "
        << endl;
    cout << "0 0 " << 0.5 + (sin(Ti11192916) * 0.5) << endl;
}

void test()
{
    double in; cin >> in;
    solve(in);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    //test(); return 0;

    Int(t);
    for (int _ = 1; _ <= t; _++) {
        cout << "Case #" << _ << ": " << endl;
        double in; cin >> in;
        solve(in);
    }

    return 0;
}






