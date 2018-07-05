#include <bits/stdc++.h>

using namespace std;

#define INF 5551000100010001000
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

int funami(int n, int kyoko)
{
    string data = to_string(n);
    int ret = 0, tmp;

    tmp = 0;
    bool fl = false;
    rep(i, data.size()) {
        if (fl) {
            for (int j = 0; j < 10; j++) {
                if ( (1 << j) & kyoko) {
                    tmp += j * (int)pow(10LL, (data.size()-i-1));
                    break;
                }
            }
        } else {
            int num = -1;
            for (int j = data[i] - '0'; j < 10; j++) {
                if ( (1 << j) & kyoko) {
                    num = j;
                    break;
                }
            }
            if (num == -1) {
                tmp = INF;
                break;
            } else if (num == data[i] - '0') {
                tmp += num * (int)pow(10LL, (data.size() - i - 1));
            } else {
                tmp += num * (int)pow(10LL, (data.size() - i - 1));
                fl = true;
            }
        }
    }
    //cout << tmp << endl;
    ret = abs(n - tmp);

    tmp = 0;
    fl = false;
    bool reading = true;
    rep(i, data.size()) {
        if (fl) {
            for (int j = 9; j >= 0; j--) {
                if ( (1 << j) & kyoko) {
                    tmp += j * (int)pow(10LL, (data.size()-i-1));
                    break;
                }
            }
        } else {
            int num = -1;
            for (int j = data[i] - '0'; j >= 0; j--) {
                if ( (1 << j) & kyoko) {
                    num = j;
                    break;
                } else if (j == 0 && reading) {
                    num = 0;
                    break;
                }
            }
            if (num == -1) {
                tmp = INF;
                break;
            } else if (num == data[i] - '0') {
                tmp += num * (int)pow(10LL, (data.size() - i - 1));
            } else {
                tmp += num * (int)pow(10LL, (data.size() - i - 1));
                fl = true;
            }
        }
        if (tmp) reading = false;
    }
    //cout << tmp << endl;
    return min(ret, abs(n - tmp));
}

int popcount(int a)
{
    int ret = 0;
    while (a) {
        ret += a % 2;
        a /= 2;
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(a, b);
    int ans = INF;
    rep(i, (1 << 10)) {
        if (popcount(i) <= b) {
            ans = min(ans, funami(a, i));
        }
    }
    cout << ans << endl;

    return 0;
}
