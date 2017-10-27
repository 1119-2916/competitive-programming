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

string ans;

void niv(int l, int r, int ket)
{
    rep(i, 4) {
        int mid = (l + r) / 2;
        ans[ket] = mid + '0';
        cout << "? " << ans << endl;
        string tmp;
        cin >> tmp;
        if (tmp == "Y") {
            r = mid;
        } else {
            l = mid;
        }
    }
    ans[ket] = (l+r)/2 + '0';
}

int parse(int ket)
{
    ket++;
    int ret = 0;
    rep(i, ket) {
        ret *= 10;
        ret += ans[i] - '0';
    }
    return ret;
}

signed main()
{
    ans = "50000000000";

    rep(i, 10) {

        niv(0, 10, i);

        cout << "? " << parse(i) << endl;
        string tmp;
        cin >> tmp;
        if (tmp == "Y") {
            cout << "! " << parse(i) << endl;
            return 0;
        }

    }
    //cout << ans << endl;
    
    return 0;
}


