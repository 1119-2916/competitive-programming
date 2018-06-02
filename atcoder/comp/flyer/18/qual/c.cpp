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

    int2(n, d);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    vi lto(n, 0), rto(n, 0);
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        while (ptr < n && data[ptr] - data[i] <= d) ptr++;
        lto[i] = ptr;
    }
    ptr = n-1;
    for (int i = n-1; i >= 0; i--) {
        while (ptr >= 0 && data[i] - data[ptr] <= d) ptr--;
        rto[i] = ptr;
    }

    /*
    rep(i, n) cout << lto[i] << " "; cout << endl;
    rep(i, n) cout << rto[i] << " "; cout << endl;
    */

    int ans = 0;
    int left = 0, right = 0;
    for (; left < n; left++) {
        right = lto[left];
        if (right - left < 2) continue;
        //cout << left+1 << " " << right+1 << endl;
        while (right < n && data[right] - data[left] <= d + d) {
            int lll = lto[left]-1, rrr = rto[right]+1;
            ans += lll - rrr + 1;
            //cout << "   " << lll << " " << rrr << endl;
            right++;
        }
    }

    cout << ans << endl;
    
    return 0;
}




