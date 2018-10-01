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

int funamiYui(int ans, int q)
{
    return (ans % q) % 2;
}

signed main()
{
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
   /* 
    int ret = 1;
    Int(ans);
    int odd = funamiYui(ans, 2);
    */
    cout << "? 2" << endl;
    int odd; string kyoko;
    cin >> kyoko;
    if (kyoko == "even") odd = 0;
    else odd = 1;
    

    int left = 1, right = 1000000001;
    while (right - left > 2) {
        int mid = (left + right) / 2;
        mid += !(mid % 2);
/*
        //cout << left << " " << right << " " << mid << "  : ";
        int tmp = funamiYui(ans, mid);
        //cout << tmp << endl;
*/
        cout << "? " << mid << endl;
        string yui; cin >> yui;
        int tmp;
        if (yui == "even") tmp = 0;
        else tmp = 1;

        if (odd == tmp) {
            right = mid;
        } else {
            left = mid;
        }
//        ret++;
    }
    cout << "! ";
    if (odd) {
        std::cout << left << std::endl;
    } else {
        std::cout << right-1 << std::endl;
    }
    //cout << ret << endl;

    return 0;
}




