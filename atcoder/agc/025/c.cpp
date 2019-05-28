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

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    priority_queue<pii> left, right;

    rep(i, n) {
        int2(a, b);
        left.push({a, i});
        right.push({-b, i});
    }

    priority_queue<pii> le = left, ri = right;
    int p = 0, ans = 0, arg = 1;
    vi used(n, 0);
    rep(i, n) {
        if (arg == 1) {
            int l = INF;
            while (l == INF && le.size()) {
                pii tmp = le.top();
                le.pop();
                if (!used[tmp.sec]) {
                    l = tmp.fir;
                    used[tmp.sec] = 1;
                }
            }
            if (l == INF) {
                continue;
            } else {
                ans += max(0ll, l - p);
                p = max(p, l);
            }
            arg = -1;
        } else {
            int r = INF;
            while (r == INF && ri.size()) {
                pii tmp = ri.top();
                ri.pop();
                if (!used[tmp.sec]) {
                    r = -tmp.fir;
                    used[tmp.sec] = 1;
                }
            }
            if (r == INF) {
                continue;
            } else {
                ans += max(0ll, p - r);
                p = min(p, r);
            }
            arg = 1;
        }
        //std::cout << p << " ";
    }
    ans += abs(p);
    //cout << ans << endl;

    le = left, ri = right;
    p = 0, arg = -1;
    int ret = 0;
    used.assign(n, 0);
    rep(i, n) {
        if (arg == 1) {
            int l = INF;
            while (l == INF && le.size()) {
                pii tmp = le.top();
                le.pop();
                if (!used[tmp.sec]) {
                    l = tmp.fir;
                }
            }
            if (l == INF) {
                continue;
            } else {
                ret += max(0ll, l - p);
                p = max(p, l);
            }
            arg = -1;
        } else {
            int r = INF;
            while (r == INF && ri.size()) {
                pii tmp = ri.top();
                ri.pop();
                if (!used[tmp.sec]) {
                    r = -tmp.fir;
                }
            }
            if (r == INF) {
                continue;
            } else {
                ret += max(0ll, p - r);
                p = min(p, r);
            }
            arg = 1;
        }
        //cout << p << " ";
    }
    ret += abs(p);
    //cout << ret << endl;

    std::cout << max(ans, ret) << std::endl;

    return 0;
}
