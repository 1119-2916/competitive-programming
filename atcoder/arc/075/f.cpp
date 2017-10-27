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
#define Edge pair< i_i, int>
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
// assign

string n;

int rev(int n)
{
    int ret = 0;
    while (n) {
        ret *= 10;
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int count(int n)
{
    int ret = 1;
    n /= 10;
    while (n) {
        ret++;
        n /= 10;
    }
    return ret;
}

int under(int n)
{
    int ret = 0;
    int ket = count(n);
    rep(i, ket/2) {
        ret *= 10;
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int solve(string st, int i, int en)
{
    int ret = 0;
    cout << i << endl;
    if (i < en) {
        for (int j = st[i]+1; j <= '9'; j++) {
            st[i] = j;
            st[en] = st[i] - n[i] + '0';
            ret += solve(st, i+1, en-1);
        }
    } else {
        if ( stoll(st) - stoll(n) == rev(stoll(st))) {
            return 1;
        } else {
            return 0;
        }
    }

}


signed main()
{
    cin >> n;

    string st(n, 0);
    cout << solve(st, 0, n.size()-1) << endl;

    return 0;
}

