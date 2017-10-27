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
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define Edge pair< int, i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dij geo2

signed main()
{
    int2(n, x);

    if (n == 2 && x == 2) {
        cout << "Yes" << endl << 1 << endl << 2 << endl << 3 << endl;
        return 0;
    }
    n = n * 2 - 1;
    if (x == 1 || x == n) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    vb used(n+1, false);
    vi ans(n, 0);
    if (x != 2) {
        for (int i = x-2; i < x+2; i++) {
            used[i] = true;
        }
        //used[x] = used[x-1] = used[x-2] = used[x+1] = true;
        int ptr = 1;
        rep(i, n / 2-1) {
            while (used[ptr]) ptr++;
            std::cout << ptr++ << std::endl;
        }
        cout << x-1 << endl << x << endl << x+1 << endl << x-2 << endl;
        while (ptr <= n) {
            while (ptr <= n && used[ptr]) ptr++;
            if (ptr > n) break;
            std::cout << ptr++ << std::endl;
        }
    } else {
        for (int i = x-1; i < x+3; i++) {
            used[i] = true;
        }
        //used[x] = used[x-1] = used[x+2] = used[x+1] = true;

        int ptr = 1;
        rep(i, n / 2-1) {
            while (used[ptr]) ptr++;
            std::cout << ptr++ << std::endl;
        }
        cout << x+1 << endl << x << endl << x-1 << endl << x+2 << endl;
        while (ptr <= n) {
            while (ptr <= n && used[ptr]) ptr++;
            if (ptr > n) break;
            std::cout << ptr++ << std::endl;
        }
    }

    return 0;
}
