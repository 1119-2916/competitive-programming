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

int cntbit(int a);
void write(int n)
{
    string tmp;
    while (n) {
        tmp.pb((n & 1)+'0');
        n >>= 1;

    }
    reverse(all(tmp));
    cout << tmp << endl;
}

signed main()
{
    int2(a, b);

    int ans = b - a + 1;
    int bita = cntbit(a), bitb = cntbit(b);

    if (a == b) {
        cout << 1 << endl;
        return 0;
    }
    while (bita == bitb) {
        int tmp = ((int)1 << (bitb - 1));
        a -= tmp; b -= tmp;
        bita = cntbit(a), bitb = cntbit(b);
    }

    int yui = 1LL << (bitb-1);
    if (b < yui+a) {
        cout << ans + yui - a << endl;
    } else {
        cout << yui - a + yui << endl;
    }

    return 0;
}


int cntbit(int a)
{
    int ret = 1;
    a >>= 1;
    while (a) {
        a >>= 1;
        ret++;
    }
    return ret;
}

