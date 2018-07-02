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

void kyoko(vi &ans, int yui, int keta, int top, int other)
{
    //cout << "call : " << yui << " " << keta << " " << top << " " << other << endl;
    vi bit(keta, 0);
    rep(i, keta) {
        //cout << yui << " ";
        bit[i] = yui % 2;
        yui /= 2;
    }
    reverse(all(bit));
    //rep(i, bit.size()) cout << bit[i]; cout << endl;
    rep(i, bit.size()) {
        if (bit[i]) {
            ans.pb(max(top, other));
        } else { 
            ans.pb(min(top, other));
        }
    }
}

void make(vi &ans, int yui, int keta)
{
    if (keta == 1) {
        ans.pb(yui + ( yui < ans[0] ? 0 : 1));
        return ;
    }

    if (yui < ((int)pow(2LL, keta-1LL) * ans[0])) {
        //cout << "top" << endl;
        int cylvie = yui - (int)pow(2LL, keta-1LL) * (yui / (int)pow(2LL, keta-1LL));
        kyoko(ans, cylvie, keta, ans[0], yui / (int)pow(2LL, keta-1LL));
    } else if (yui < ((int)pow(2LL, keta-1LL) * ans[0]) +
            ((int)pow(2LL, keta-1LL) -1LL) * 9LL) {
        //cout << "med" << endl;
        ans.pb(ans[0]);
        yui -= ((int)pow(2LL, keta-1LL) * ans[0]);
        make(ans, yui, keta-1);
    } else {
        //cout << "bot" << endl;
        int muda = ((int)pow(2LL, keta-1LL) * ans[0]) +
            ((int)pow(2LL, keta-1LL) - 1LL) * 9LL;
        yui -= muda;
        ans.pb(yui / ((int)pow(2LL, keta-1LL)) + 1 + ans[0]);

        kyoko(ans, yui, keta-1, ans[0], ans.back());
        /*
        kyoko(ans, yui, keta, ans[0], 
                (yui - 
( ((int)pow(2LL, keta-1LL) * ans[0]) + (((int)pow(2LL, keta-1LL) - 1LL) * 9LL)) )
                / (int)pow(2LL, keta-1LL) + 1 + ans[0]);
                */
    }
}

void solve(vi &ans, int yui, int keta)
{
    ans.pb( yui / (((int)pow(2LL, keta-1LL)-1LL) * 9LL) + 1LL);
    yui -= (((int)pow(2LL, keta-1LL)-1LL) * 9LL) * (ans[0]-1);
    make(ans, yui, keta-1LL);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    while (n) {
        int keta, yui, tmp = 0;
        Rep(i, INF) {
            if (tmp + ((int)pow(2LL, i)-1LL) * 81LL < n) {
                tmp += ((int)pow(2LL, i)-1LL) * 81LL;
            } else {
                keta = i+1;
                yui = n - tmp - 1;
                break;
            }
        }
        vi ans;
        //cout << keta << " " << yui << endl;
        solve(ans, yui, keta);
        rep(i, ans.size()) {
            cout << ans[i];
        }
        cout << endl;
        cin >> n;
    }

    return 0;
}
