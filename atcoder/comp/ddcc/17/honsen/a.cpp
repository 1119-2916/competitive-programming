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

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

int solve(int k, int size)
{
    int ret = 0;
    int dx[4] = {0, k, 0, k}, dy[4] = {0, 0, k, k};
    for (int i = 0; i < size; i += k) {
        for (int j = 0; j < size; j += k) {
            bool ok = true;
            for (int l = 0; l < 4; l++) {
                int x = i + dx[l], y = j + dy[l];
                if ( (size/2 - x) * (size/2 - x) +
                        (size/2 - y) * (size/2 - y) > size * size / 4) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ret++;
            }
        }
    }
    return ret;
}



signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(k);

    cout << solve(k, 200) << " " << solve(k, 300) << endl;




    return 0;
}







