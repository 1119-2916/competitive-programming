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

string st;
int p;
pii term_calc;

pii term();
pii and_expr();
pii or_expr();

pii term()
{
    pii ret;
    if (st[p] == '(') {
        p++;
        ret = or_expr();
        p++;
        return ret;
    } else if (st[p] == '?') {
        p++;
        return term_calc;
    } else {
        assert(0);
        return {-1, -1};
    }
}

pii and_expr()
{
    pii ret = term();
    int ret_1 = ret.first;
    int ret_0 = ret.second;
    int ret_sum = ret.first;
    while (st[p] == '&') {
        p++;
        ret = and_expr();
        ret_1 += ret.first;
        ret_0 = min(ret_sum + ret.second, ret_0);
        ret_sum += ret.first;
    }
    return {ret_1, ret_0};
}

pii or_expr()
{
    pii ret = and_expr();
    int ret_0 = ret.second;
    int ret_1 = ret.first;
    int ret_sum = ret.second;
    while (st[p] == '|') {
        p++;
        ret = and_expr();
        ret_0 += ret.second;
        ret_1 = min(ret_sum + ret.first, ret_1);
        ret_sum += ret.second;
    }
    return {ret_1, ret_0};
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    term_calc = {1, 1};
    cin >> st;
    p = 0;

    auto ans = or_expr();
    std::cout << ans.sec << " " << ans.fir << endl;

    return 0;
}
