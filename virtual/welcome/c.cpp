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

bool check(vi &data)
{
    rep(i, data.size()) {
        if (data[i]) return true;
    }
    return false;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    vi mmn(26, 0), mm(10, 0);
    string st;
    cin >> st;
    
    rep(i, st.size()) {
        if (in(st[i], '0', '9'+1)) {
            mm[st[i] - '0']++;
        } else {
            mmn[st[i] - 'a']++;
        }
    }
/*
    rep(i, mmn.size()) {
        cout << mmn[i] << " ";
    }cout << endl;
*/
    int ans = 0;
    while (check(mmn)) {
        int ptr = 0;
        while (!mmn[ptr]) ptr++;
        int len = 0;
        for (; ptr < mmn.size(); ptr++) {
            if (mmn[ptr]) {
                len++;
                mmn[ptr]--;
            } else {
                break;
            }
        }
        if (len >= 3) ans += 3;
        else ans += len;
        //cout << len << " " << ans << endl;
    }

    /*
    rep(i, mm.size()) {
        cout << mm[i] << " ";
    }cout << endl;
    */
    while (check(mm)) {
        int ptr = 0;
        while (!mm[ptr]) ptr++;
        int len = 0;
        for (; ptr < mm.size(); ptr++) {
            if (mm[ptr]) {
                len++;
                mm[ptr]--;
            } else {
                break;
            }
        }
        if (len >= 3) ans += 3;
        else ans += len;
        //cout << len << " " << ans << endl;
    }

    std::cout << ans << std::endl;

    return 0;
}
