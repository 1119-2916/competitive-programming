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

double solve(int time, double el, double er, double l, double r, double score, double p)
{
    double m = (l + r) / 2.0, t = (er + el) / 2.0, ret = 0.0;
    if (!time) return (el <= m && m <= er) ? score : ret;
    if (el <= l && r <= er) return score;
    if (r < el || er < l) return 0.0;
    double ml = (l + m) / 2.0, mr = (r + m) / 2.0;
    ret += solve(time-1, el, er, l, m, score * ((abs(mr - t) <= abs(ml - t)) ? p : 1 - p), p);
    ret += solve(time-1, el, er, m, r, score * ((abs(mr - t) <= abs(ml - t)) ? 1 - p : p), p);
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(k, r, l);
    double p, e, t;
    cin >> p >> e >> t;

    cout << Decimal << solve(k, t - e, t + e, r, l, 1.0, p) << endl;

    return 0;
}

