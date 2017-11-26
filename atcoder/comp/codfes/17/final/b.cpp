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

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string st;
    cin >> st;
    if (st.size() == 1) {
        cout << "YES" << endl;
        return 0;
    }
    vi cnt(3, 0);

    rep(i, st.size()) {
        cnt[st[i] - 'a']++;
    }

    int tmp = min(cnt[0], min(cnt[1], cnt[2]));
    rep(i, 3) {
        cnt[i] -= tmp;
        //cout << cnt[i] << endl;
    }

    rep(i, 3) {
        if (1 < cnt[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    /*
    if (cnt[0] == cnt[2] && cnt[1] == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    */
    cout << "YES" << endl;



    return 0;
}
