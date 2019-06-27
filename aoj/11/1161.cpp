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


int solve(vi &used, map<char, int> &calc, vector<char> &mojis, set<char> &notzero, int keta, int sum)
{
    if (keta == mojis.size() && !sum) return 1;
    else if (keta == mojis.size()) return 0;

    int ret = 0;
    rep(i, 10) {
        if (!i && notzero.find(mojis[keta]) != notzero.end()) continue;
        if (!used[i]) {
            used[i] = 1;
            ret += solve(used, calc, mojis, notzero, keta+1, sum + calc[mojis[keta]] * i);
            used[i] = 0;
        }
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    while (cin >> n, n) {
        vector<string> input(n);
        vector<char> mojis;
        set<char> notzero;
        map<char, int> calc;
        rep(i, n) {
            cin >> input[i];
            rep(j, input[i].size()) {
                mojis.eb(input[i][j]);
            }
            if (input[i].size() != 1) notzero.insert(input[i][0]);
            if (i+1 == n) {
                rep(j, input[i].size()) {
                    calc[input[i][j]] -= pow(10, (input[i].size() - j - 1));
                }
            } else {
                rep(j, input[i].size()) {
                    calc[input[i][j]] += pow(10, (input[i].size() - j - 1));
                }
            }
        }
        sort(all(mojis));
        auto tmp = unique(all(mojis));
        mojis.erase(tmp, mojis.end());

        vi used(10, 0);
        cout << solve(used, calc, mojis, notzero, 0, 0) << endl;
    }

    return 0;
}
