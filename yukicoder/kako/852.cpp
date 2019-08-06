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

    string st;
    cin >> st;

    int n = st.size();
    
    vi pos(26, 0);
    vi cnt(27, 0);
    rep(i, n) {
        pos[st[i] - 'a'] = i+1;
        /*
        rep(j, pos.size()) {
            cout << pos[j] << " ";
        }
        cout << endl;
        */
        vi sorted = pos;
        sorted.emplace_back(0);
        sort(all(sorted));
        reverse(all(sorted));
        Rep(j, sorted.size()) {
            cnt[j] += sorted[j-1] - sorted[j];
        }
    }

    int sum = 0;
    rep(i, cnt.size()) {
        sum += cnt[i] * i;
        //std::cout << cnt[i] << std::endl;
    }

    cout << Decimal << (double)sum / (n * (n+1) / 2.0) << endl;

    return 0;
}
