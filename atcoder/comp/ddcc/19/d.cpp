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

pii solve(int k, int n)
{
    //cout << "call : " << k << ", " << n << endl;
    if (n == 1L) return {0L, k};

    pii ret;
    if (k + k >= 10L) {
        ret = solve((k + k) / 10L + (k + k) % 10L, n/2L);
        ret.first += n - (n % 2);
    } else {
        ret = solve(k + k, n/2L);
        ret.first += n/2L;
    }
    if (n % 2L) {
        if (ret.second + k >= 10L) {
            ret.first += 2L;
            ret.second = (ret.second + k) / 10L + (ret.second + k) % 10L;
        } else {
            ret.first++;
            ret.second += k;
        }
    }

    //cout << "return : " << ret.fir << " " << ret.sec << endl;

    return ret;
}

int funami(vi &state)
{
    int s = state[0];
    int ans = 0L;
    Rep(i, state.size()) {
        s += state[i];
        ans++;
        if (s >= 10L) {
            ans++;
            s = s / 10L + s % 10L;
        }
    }
    return ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<pii> data(n);
    rep(i, n) {
        cin >> data[i].fir >> data[i].sec;
    }

    vi state;
    int ans = 0L;
    rep(i, n) {
        pii tmp = solve(data[i].fir, data[i].sec);
        ans += tmp.fir;
        state.pb(tmp.sec);
    }

    cout << ans + funami(state) << endl;

    return 0;
    int my = ans + funami(state);

    // ~~~ test ~~~ 

    int length = 0;
    rep(i, data.size()) length += data[i].sec;
    vi input(length);
    int p = 0;
    rep(i, data.size()) {
        rep(j, data[i].sec) {
            input[p++] = data[i].fir;
        }
    }

    int collect = funami(input);
    if (collect != my) {
        //cout << "EWOEOEEEEEEEEEEWOEOWOEO" << endl;
        cout << n << endl;
        rep(i, n) {
            cout << data[i].fir << " " << data[i].sec << endl;
        }
        cout << my << " " << collect << endl;
        return 0;
    }

    return 0;
}
