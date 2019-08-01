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

    int2(n, k);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    //k = (k-1) % (n+1);
    k--;
    //std::cout << "k : " << k << std::endl;
    
    vi nxt(n);
    map<int, int> tmp;
    rep(i, n) {
        if (tmp.find(data[i]) != tmp.end()) {
            nxt[tmp[data[i]]] = i;
        }
        tmp[data[i]] = i;
    }
    rep(i, n) {
        if (tmp.find(data[i]) != tmp.end()) {
            nxt[tmp[data[i]]] = i;
        }
        tmp[data[i]] = i;
    }

    /*
    rep(i, n) {
        cout << nxt[i] << " ";
    }
    cout << endl;
    */

    //cout << "hop : ";
    int p = 0, hopcnt = 0;
    //while (k && p != n) {
    while (p != n) {
        //cout << p << " ";
        if (p < nxt[p]) {
            p = nxt[p];
        } else {
            //k--;
            hopcnt++;
            p = nxt[p];
        }
        //p = (p + 1) % n;
        p++;
    }
    //cout << p << endl;

    k = k % (hopcnt+1);
    p = 0;
    while (k) {
        if (p < nxt[p]) {
            p = nxt[p];
        } else {
            k--;
            p = nxt[p];
        }
        p++;
    }

    //if (!p) return 0;
    while (p < n) {
        if (p < nxt[p]) {
            p = nxt[p];
        } else {
            cout << data[p] << " ";
        }
        p++;
    }
    cout << endl;

    return 0;
}
