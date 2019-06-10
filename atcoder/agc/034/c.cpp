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

    int2(n, x);
    vi low(n), up(n), point(n);
    vp data(n);
    int score = 0;
    rep(i, n) {
        cin >> point[i] >> low[i] >> up[i];
        score += point[i] * low[i];
        data[i].fir = up[i] * (x - point[i]) + point[i] * low[i];
        data[i].sec = i;
    }
    if (!score) {
        std::cout << 0 << std::endl;
        return 0;
    }

    //cout << "score : " << score << endl;
    sort(all(data)); reverse(all(data));

    int l = 0, r = x * n;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        vi used(n, 0);
        //cout << "mid : " << mid << endl;

        int p = 0, sum = 0;
        while (mid >= x) {
            sum += data[p].fir;
            used[p] = 1;
            p++; mid -= x;
        }
        //cout << sum << " : ";

        int yui = sum;
        rep(i, data.size()) {
            if (!used[i]) {
                if (mid <= point[data[i].sec]) {
                    yui = max(yui, sum + mid * low[data[i].sec]);
                } else {
                    yui = max(yui,
                            sum + point[data[i].sec] * low[data[i].sec] + 
                            (mid - point[data[i].sec]) * up[data[i].sec]);
                }
            } else if (p < data.size()) {
                int tmp = sum - data[i].fir + data[p].fir;
                //cout << " [tmp : " << tmp << "] "; 
                if (mid <= point[data[i].sec]) {
                    yui = max(yui, tmp + mid * low[data[i].sec]);
                } else {
                    yui = max(yui,
                            tmp + point[data[i].sec] * low[data[i].sec] + 
                            (mid - point[data[i].sec]) * up[data[i].sec]);
                }
            }
            //cout << yui << ", ";
        }
        //cout << endl;
        if (yui >= score) {
            r = (r + l) / 2;
        } else {
            l = (r + l) / 2;
        }
    }
    std::cout << r << std::endl;
    return 0;
}
