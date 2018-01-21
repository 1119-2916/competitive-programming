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
    string st;
    cin >> st;
    
    bool fl = false;
    int l = 0;
    for (; l < st.size(); l++) {
        if (st[l] == 'B') {
            fl = true;
            break;
        }
    }
    int sum = 0, r = 0;
    for (r = st.size()-1; r >= 0; r--) {
        if (st[r] == 'B') {
            break;
        }
    }
    int cnt = 0;
    for (int i = l; i < r; i++) {
        if (st[i] == 'A') {
            cnt++;
            sum += cnt;
        } else {
            cnt = 0;
        }
    }
    r = (st.size() - r - 1);
    //cout << l << sum << r << fl << endl;
    if (fl) {
        cout << (l * (l + 1) / 2) + sum * n + (r * (r + 1) / 2) +
            (l+r) * (l+r+1) / 2 * (n-1) << endl;
    } else {
        cout << (st.size()*n) * (st.size()*n+1) / 2 << endl;
    }




    return 0;
}
