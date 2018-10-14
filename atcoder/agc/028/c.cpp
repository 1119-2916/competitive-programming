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
    vp data(n);
    rep(i, n) {
        cin >> data[i].fir >> data[i].sec;
    }

    priority_queue<pair<int, pair<int, int>>> funami, toshino;
    rep(i, n) {
        funami.push({-data[i].fir, {i, 0}});
        funami.push({-data[i].sec, {i, 1}});
    }

    toshino = funami;
    int p = toshino.top().ssec;
    bool fl = true;
    toshino.pop();
    //cout << "p : " << p << " ";
    rep(i, n-1) {
        //cout << toshino.top().ssec << " ";
        if (toshino.top().ssec != p) {
            fl = false;
            break;
        }
        toshino.pop();
    }
    //cout << endl;

    if (fl) {
        int ans = 0;
        rep(i, n) {
            ans -= funami.top().fir;
            funami.pop();
        }
        //cout << "fast" << endl;
        cout << ans << endl;
        return 0;
    }

    vector<int> hoge(n, 0);
    int cnt = 0, state = 0, ans = 0;
    while (1) {
        int ptr = funami.top().sfir;
        //cout << ptr << endl;
        if (hoge[ptr]) {
            state++;
            cnt++;
            ans -= funami.top().fir;
        } else {
            hoge[ptr] = 1;
            if (cnt < n-1 || state) {
                ans -= funami.top().fir;
                cnt++;
            }
        }
        cout << funami.top().fir << " " << ans << " " << cnt << endl;
        funami.pop();
        if (cnt >= n && state) {
            cout << ans << endl;
            break;
        }
    }


    return 0;
}


