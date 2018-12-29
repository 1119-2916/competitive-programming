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

bool solve(vi &data, int num)
{
    int n = data.size();
    vi mmnmm(n, 0);
    mmnmm[0] = 1;
    Rep(i, n) {
        if (data[i-1] < data[i]) {
            mmnmm[i] = (mmnmm[i]-1) * (pow(num, data[i] - data[i-1])) + 1;
        } else if (data[i-1] > data[i]) {
            mmnmm[i] = (mmnmm[i-1] / pow(num, data[i-1] - data[i])) + 1;
        } else {
            mmnmm[i] = mmnmm[i-1] + 1;
        }
    }

    bool yui = true;
    rep(i, n) {
        if (pow(num, data[i]) < mmnmm[i]) {
            yui = false;
        }
    }
    rep(i, n) {
        cout << mmnmm[i] << " ";
    }cout << endl;
    return yui;
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
    
    {
        bool yui = true;
        Rep(i, n) {
            if (data[i] >= data[i+1]) {
                yui = false;
            }
        }
        if (yui) {
            std::cout << 1 << std::endl;
            return 0;
        }
    }

    int left = 1, right = 101000;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (solve(data, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    std::cout << right << std::endl;

    return 0;
}



