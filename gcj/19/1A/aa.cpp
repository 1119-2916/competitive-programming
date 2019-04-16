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
//
#pragma optimization level 2

int check(vector<string> input, int p)
{
    rep(i, p) if (input[i] == "") return 0;
    if (p == 2) return (input[0] != input[1]) ? 4 : 0;
    if (p == 3) {
        return ((input[0] != input[1]) && (input[0] != input[2]) && (input[1] != input[2])) ? 6 : 0;
    }
    return 2;
}

string getSs(string a, string b, int p)
{
    string ret = "";
    rep(i, p) {
        if (a[i] == b[i]) {
            ret += a[i];
        } else {
            return "";
        }
    }
    return ret;
}

int solve()
{
    Int(n);
    vector<string> data(n);
    rep(i, n) {
        cin >> data[i];
        reverse(all(data[i]));
    }
    sort(all(data));

    int ans = 0;
    do {
        vector<string> funami(n/2, "");
        if (n >= 2) {
            rep(i, min(data[0].size(), data[1].size())) {
                funami[0] = getSs(data[0], data[1], i+1);
                if (funami[0] == "") break;
                ans = max(ans, check(funami, 1));
                if (n >= 4) {
                    rep(j, min(data[2].size(), data[3].size())) {
                        funami[1] = getSs(data[2], data[3], j+1);
                        if (funami[1] == "") break;
                        ans = max(ans, check(funami, 2));
                        if (n >= 6) {
                            rep(k, min(data[4].size(), data[5].size())) {
                                funami[2] = getSs(data[4], data[5], k+1);
                                if (funami[2] == "") break;
                                ans = max(ans, check(funami, 3));
                            }
                        }
                    }
                }
            }
        }
    } while (next_permutation(all(data)));

    return ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(T);
    for (int i = 0; i < T; i++) {
        cout << "Case #" << i+1 << ": " << solve() << "\n";
    }

    return 0;
}
