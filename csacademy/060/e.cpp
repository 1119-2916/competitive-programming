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

string to_st(int a, int keta)
{
    string ret;
    rep(i, keta) {
        ret.pb(a % 2 + '0');
        a /= 2;
    }
    return ret;
}

string solve(string a, string b)
{
    if (a == "hoge") return b;
    int aa = 0, bb = 0, aaa = 0, bbb = 0;
    rep(i, a.size()) {
        if (a[i] == '1') aa++;
        else aaa++;
    }
    rep(i, b.size()) {
        if (b[i] == '1') bb++;
        else bbb++;
    }
    /*
    cout << a << " " << b << endl;
    cout << aa << " " << bb << endl;
    */
    if (abs(aaa - aa) < abs(bbb - bb)) {
        return a;
    } else {
        return b;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<i_i> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].fir >> data[i].sec;
    }

    if (n == 1) {
        if (data[0].fir == 0) 
            cout << "0" << endl;
        else if (data[0].sec == 0) 
            cout << "1" << endl;
        else 
            cout << "-1" << endl;
        return 0;
    }


    vi funami;
    multimap<int, string> yui;

    rep(i, (1 << (n/2))) {
        int tmp = 0, state = i;
        rep(j, n/2) {
            if (state % 2) {
                tmp -= data[j].sec;
            } else {
                tmp += data[j].fir;
            }
            state /= 2;
        }
        funami.pb(tmp);
        yui.insert(mp(tmp, to_st(i, n/2)));
    }
    sort(all(funami));
    auto hoge = unique(all(funami));
    //funami.erase(hoge, funami.end());

    string ans = "hoge";

    rep(i, (1 << (n - n/2))) {
        int tmp = 0, state = i;
        rep(j, n - n/2) {
            if (state % 2) {
                tmp -= data[n/2+j].sec;
            } else {
                tmp += data[n/2+j].fir;
            }
            state /= 2;
        }
        auto funamiyui = lower_bound(funami.begin(), hoge, -tmp);
        if (*funamiyui == -tmp) {
            auto kyoko = yui.equal_range(*funamiyui);
            for (auto it = kyoko.first; it != kyoko.second; ++it) {
                ans = solve(ans, it->second + to_st(i, n-n/2));
            }
        }
    }
    if (ans == "hoge") 
        cout << -1 << endl;
    else 
        cout << ans << endl;

    return 0;
}




