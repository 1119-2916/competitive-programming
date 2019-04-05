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

    int2(n, m);
    string st;
    cin >> st;
    
    vector<pair<char, int>> data(m);
    rep(i, m) {
        string a;
        cin >> a;
        data[i].fir = a[0];
        string b;
        cin >> b;
        if (b == "R") {
            data[i].sec = 0;
        } else {
            data[i].sec = 1;
        }
    }

    reverse(all(data));

    vi ans(n, 0);
    int p1 = -1, pn = n;
    rep(i, data.size()) {
        if (data[i].sec) {
            if (in(p1 + 1, 0, n) && st[p1+1] == data[i].fir) {
                p1++;
                ans[p1] = 1;
            }
            //*
            if (in(pn + 1, 0, n) && st[pn+1] == data[i].fir) {
                pn++;
                ans[pn] = 1;
            }
            else 
            if (in(pn, 0, n) && st[pn] == data[i].fir) {
                pn++;
            }
            //*/
        } else {
            //*
            if (in(p1 - 1, 0, n) && st[p1-1] == data[i].fir) {
                p1--;
                ans[p1] = 1;
            }
            else 
            if (in(p1, 0, n) && st[p1] == data[i].fir) {
                p1--;
            }
            //*/
            if (in(pn - 1, 0, n) && st[pn-1] == data[i].fir) {
                pn--;
                ans[pn] = 1;
            }
        }
        //*
        std::cout << " p : " << p1 << " " << pn << std::endl;
        rep(j, n) {
            std::cout << ans[j] << " ";
        }
        cout << endl;
        //*/
    }

    int yui = 0;
    rep(i, n) {
        yui += ans[i];
        //std::cout << ans[i] << " ";
    }
    //cout << endl;

    std::cout << n - yui << std::endl;



    return 0;
}



