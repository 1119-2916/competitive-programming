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

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(h1, a1, c);
    int2(h2, a2);
    int ans = 0;
    string st = "STRIKE", he = "HEAL";
    vector<string> output(0);
    while (h2 > 0) {
        if (h1 <= a2 && a1 < h2) {
            output.pb(he);
            h1 += c - a2;
        } else {
            output.pb(st);
            h2 -= a1;
            h1 -= a2;
        }
        //cout << h1 << " " << h2 << endl;
    }
    cout << output.size() << endl;
    rep(i, output.size()) {
        cout << output[i] << endl;
    }


    return 0;
}






