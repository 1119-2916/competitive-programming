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

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string st;
    cin >> st;
    int2(a, b);
    bool funamiyuichannhakawaiinaa = false;
    if (st[0] == 'F') {
        funamiyuichannhakawaiinaa = true;
    }

    vi dx(0), dy(0);
    int cnt = 0, hop = 0;
    rep(i, st.size()) {
        if (st[i] == 'T') {
            if (hop) {
                if (cnt % 2) {
                    dy.pb(hop);
                } else {
                    dx.pb(hop);
                }
                hop = 0;
            }
            cnt++;
        } else {
            hop++;
        }
    }
    if (hop) {
        if (cnt % 2) {
            dy.pb(hop);
        } else {
            dx.pb(hop);
        }
    }
    /*
    rep(i, dx.size()) cout << dx[i] << " ";
    cout << endl;

    rep(i, dy.size()) cout << dy[i] << " ";
    cout << endl;
    */

    set<int> funami;
    if (dx.size() != 0 && funamiyuichannhakawaiinaa) {
        funami.insert(dx[0]);
    } else {
        funami.insert(0);
    }
    for (int i = (funamiyuichannhakawaiinaa) ? 1 : 0; i < dx.size(); i++) {
        set<int> kyoko;
        for (auto j = funami.begin(); j != funami.end(); j++) {
            kyoko.insert(*j+dx[i]);
            kyoko.insert(*j-dx[i]);
        }
        funami = kyoko;
    }
    if (funami.find(a) == funami.end()) {
        cout << "No" << endl;
        return 0;
    }

    funami = set<int>();
    funami.insert(0);
    rep(i, dy.size()) {
        set<int> kyoko;
        for (auto j = funami.begin(); j != funami.end(); j++) {
            kyoko.insert(*j+dy[i]);
            kyoko.insert(*j-dy[i]);
        }
        funami = kyoko;
    }
    if (funami.find(b) == funami.end()) {
        cout << "No" << endl;
        return 0;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}




