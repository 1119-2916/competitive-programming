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

int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(h, w);
    bool fl = false, ffl = true;
    vvi data(h, vi(w));
    rep(i, h) {
        rep(j, w) {
            cin >> data[i][j];
            if (data[i][j] == 5) fl = true;
            if (data[i][j]) ffl = false;
        }
    }

    if (ffl) {
        std::cout << "Yes 0" << std::endl;
        return 0;
    }
    if (!fl) {
        std::cout << "No" << std::endl;
        return 0;
    }

    if (h == 1) {
        int ans = INF;
        rep(i, w) {
            if (data[h-1][i] == 5) {
                int ret = 0, yui = 0;
                rep(j, i) {
                    yui = max(yui, data[h-1][j]);
                }
                if (yui == 9) {
                    ret += 3;
                } else if (yui == 8) {
                    ret += 2;
                } else if (yui == 7) {
                    ret += 1;
                } else if (yui == 6) {
                    ret += 1;
                }
                yui = 0;
                for (int j = i+1; j < w; j++) {
                    yui = max(yui, data[h-1][j]);
                }
                if (yui == 9) {
                    ret += 3;
                } else if (yui == 8) {
                    ret += 2;
                } else if (yui == 7) {
                    ret += 1;
                } else if (yui == 6) {
                    ret += 1;
                }
                ans = min(ans, ret + 1);
            }
        }
        std::cout << "Yes " << ans << std::endl;
    } else if (w == 1) {
        int ans = INF;
        rep(i, h) {
            if (data[i][w-1] == 5) {
                int ret = 0, yui = 0;
                rep(j, i) {
                    yui = max(yui, data[j][w-1]);
                }
                if (yui == 9) {
                    ret += 3;
                } else if (yui == 8) {
                    ret += 2;
                } else if (yui == 7) {
                    ret += 1;
                } else if (yui == 6) {
                    ret += 1;
                }
                yui = 0;
                for (int j = i+1; j < h; j++) {
                    yui = max(yui, data[j][w-1]);
                }
                if (yui == 9) {
                    ret += 3;
                } else if (yui == 8) {
                    ret += 2;
                } else if (yui == 7) {
                    ret += 1;
                } else if (yui == 6) {
                    ret += 1;
                }
                ans = min(ans, ret + 1);
            }
        }
        std::cout << "Yes " << ans << std::endl;
    } else {
        int ret = 0, ans = 0;
        rep(i, h) {
            rep(j, w) {
                ret = max(ret, data[i][j]);
            }
        }

        if (ret == 9) {
            ans += 3;
        } else if (ret == 8) {
            ans += 2;
        } else if (ret == 7) {
            ans += 1;
        } else if (ret == 6) {
            ans += 1;
        }

        std::cout << "Yes " << ans + 1 << std::endl;
    }

    return 0;
}
