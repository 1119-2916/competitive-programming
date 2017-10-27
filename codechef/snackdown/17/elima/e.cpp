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
 
signed main()
{
    Int(dataset);
    while (dataset--) {

        int2(n, k);
        Int(snakes);

        vp tate, yoko;

        int hx, hy, tx, ty;
        int space = (n - k) / 2;
        rep(i, snakes) {
            cin >> hx >> hy >> tx >> ty;
            int tmpmin = min(hx, tx), tmpmax = max(hx, tx);
            hx = tmpmin, tx = tmpmax;
            if (tx <= space || n - space < hx) {
                ;;
            } else {
                tate.pb(i_i(hx, -tx));
            }
            tmpmin = min(hy, ty); tmpmax = max(hy, ty);
            hy = tmpmin, ty = tmpmax;
            if (ty <= space || n - space < hy) {
                ;;
            } else {
                yoko.pb(i_i(hy, -ty));
            }
        }

        sort(all(tate));
        sort(all(yoko));
        int state = space+1, ans = 0;

        int ptr = 0;
        /*
        for (i_i tmp : tate) {
            cout << tmp.fir << tmp.sec << endl;

        }*/
        
        while (state < n - space + 1 && ptr < tate.size()) {
            int maxptr = ptr;
            while (tate[ptr].first <= state && ptr < tate.size()) {
                if (-tate[maxptr].sec < -tate[ptr].sec) {
                    maxptr = ptr;
                }
                ptr++;
            }
            if (state < tate[maxptr].fir) {
                ans = -1;
                break;
            }
            state = -tate[maxptr].sec + 1;
            ans++;
        }
        if (ans == -1 || state < n - space + 1) {
            cout << -1 << endl;
            continue;
        } else {
           // cout << ans << endl;
        }
      //  cout << state << endl;

        ptr = 0; state = space+1;
        while (state < n - space + 1 && ptr < yoko.size()) {
            int maxptr = ptr;
            while (yoko[ptr].first <= state && ptr < yoko.size()) {
                if (-yoko[maxptr].sec < -yoko[ptr].sec) {
                    maxptr = ptr;
                }
                ptr++;
            }
            if (state < yoko[maxptr].fir) {
                ans = -1;
                break;
            }
            state = -yoko[maxptr].sec + 1;
          //  cout << "state" <<  state << endl;
            ans++;
        }
        //cout << state << " " << n - space << endl;
        if (ans == -1 || state < n - space + 1) {
            cout << -1 << endl;
            continue;
        } else {
       //     cout << ans << endl;
        }

        /*
        for (i_i tmp : yoko) {
            cout << tmp.fir << tmp.sec << endl;
        }*/
        
        cout << ans << endl;
        //cout << endl;
    }


    return 0;
}





