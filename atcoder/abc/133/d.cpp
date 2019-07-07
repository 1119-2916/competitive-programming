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

void output(vi &data, int p)
{
    rep(i, data.size()) {
        cout << p*2 << " ";
        p = data[i] - p;
    }
    cout << endl;
}

int solve(vi &data, int p)
{
    //cout << "call : ";
    int ptr = p;
    rep(i, data.size()) {
        //cout << ptr << " ";
        if (data[i] < ptr) {
            //cout << endl;
            return -1;
        }
        ptr = data[i] - ptr;
    }
    //cout << ptr << endl;
    return !(ptr == p);
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

    int yui = 0;
    rep(i, n) {
        yui = data[i] - yui;
    }
    output(data, yui/2);

    return 0;

    int l = 0, r = data[0];
    if (solve(data, 0) == 0) {
        output(data, 0);
        return 0;
    }
    if (solve(data, data[0]) == 0) {
        output(data, data[0]);
        return 0;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int state = solve(data, mid);
        if (state < 0) {
            l = mid;
        } else if (state == 0) {
            output(data, mid);
            break;
        } else {
            r = mid;
        }
    }

    return 0;
}
