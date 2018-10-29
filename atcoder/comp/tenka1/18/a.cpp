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

int solve(vi &data)
{
    int ret = 0;
    int bef = 0, aft = data.size()-1;
    int now = data[bef] * 2;

    //cout << "call : " << endl;
    //rep(i, data.size()) cout << data[i] << " "; cout << endl;

    rep(i, data.size()) {
        //cout << "now = " << now << " bef = " << bef << " aft = " << aft << endl;
        if (i % 2) {
            if (bef+1 < aft) { // 2ko
                int tmp = data[bef+1] + data[bef+2];
                bef += 2;
                ret += (abs(now - tmp));
                now = tmp;
            } else if (bef < aft) {  // 1ko
                int tmp = data[bef+1];
                bef += 1;
                ret += max(abs(data[aft+2] - tmp), abs(data[aft+1] - tmp));
                break;
            } else {
                break;
            }
        } else {
            if (bef+1 < aft) { // 2ko
                int tmp = data[aft] + data[aft-1];
                aft -= 2;
                ret += (abs(now - tmp));
                now = tmp;
            } else if (bef < aft) {  // 1ko
                int tmp = data[aft];
                if (data.size() == 2) {
                    ret += abs(data[0] - tmp);
                } else {
                    ret += max(abs(data[bef] - tmp), abs(data[bef-1] - tmp));
                }
                now = tmp;
                break;
            } else {
                break;
            }
        }
        //cout << now << " " << ret << endl;
    }

    return ret;
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    sort(all(data));
    int ans = solve(data);
    //cout << ans << endl;
    reverse(all(data));
    ans = max(ans, solve(data));

    cout << ans << endl;

    return 0;
}
