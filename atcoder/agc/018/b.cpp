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

signed main()
{
    int2(n, m);
    vvi data(n, vi(m));
    rep(i, n) {
        rep(j, m) {
            cin >> data[i][j];
        }
    }

    int l = 0, r = n+1;
    while (r - l > 1) {
        int targ = (l + r) / 2;
        //Rep(targ, n+1) {

        bool clear = false;
//        cout << "targ === " << targ << endl;
        vb used(m, true);
        while (1) {
            vb isOk(n, false);
            vi cnt(m, 0);

            rep(j, m) { // 優先順位
                rep(i, n) {
                    if (!isOk[i]) {
                        if (used[data[i][j]-1]) {
                            isOk[i] = true;
                            cnt[data[i][j]-1]++;
                        }
                    }
                }
            }
            bool state = true;
            rep(i, n) {
                if (!isOk[i]) {
                    state = false;
                    break;
                }
            }
            if (!state) {
                break;
            }

            /*
               std::cout << "====cnt====" << std::endl;
               rep(i, m) {
               std::cout << cnt[i] << " ";
               }cout << endl;
               std::cout << "===========" << std::endl;
               */

            int ptr = 0;
            Rep(i, m) {
                if (cnt[ptr] < cnt[i]) {
                    ptr = i;
                }
            }
            //cout << "ptr" << ptr << endl;
            if (cnt[ptr] > targ) {
                used[ptr] = false;
            } else {
                clear = true;
                break;
            }
        }

        if (clear) {
            r = targ;
            //cout << targ << endl;
            //return 0;
        } else {
            l = targ;
        }
    }
    cout << r << endl;


    return 0;
    }
