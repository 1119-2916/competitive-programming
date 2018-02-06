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

    Int(n);
    int yui = 0, kyoko = 0, aless = 0, bless = 0;
    vector<int> aa(n);
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }
    vector<int> bb(n);
    for (int i = 0; i < n; i++) {
        cin >> bb[i];
    }
    
    rep(i, n) {
        int a = aa[i], b = bb[i];
        yui += a;
        kyoko += b;
        if (a < b) {
            aless += (b - a) / 2 + (b - a) % 2;
            bless += (b - a) % 2;
        } else if (b < a) {
            bless += a - b;
        }
    }
    int less = kyoko - yui;
    aless = less - aless;
    bless = less - bless;
    //cout << less << endl;
    if (less < 0) {
        cout << "No" << endl;
    } else if (less == 0) {
        if (!aless && !bless) {
            cout << "Yes" << endl;
        } else {
            std::cout << "No" << std::endl;
        }
    } else {
        //cout << aless << " " << bless << endl;
        if (aless < 0 || bless < 0) {
            std::cout << "No" << std::endl;
        } else if (aless * 2 == bless) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}


