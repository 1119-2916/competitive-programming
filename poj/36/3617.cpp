#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

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
// assign
 
signed main()
{
    Int(n);
    string a;
    rep(i, n) {
        char tmp;
        cin >> tmp;
        a.pb(tmp);
    }

    int ap = 0, bp = n-1;
    int newline = 0;
    while (ap <= bp) {
        if (newline == 80) {
            cout << endl;
            newline = 0;
        }
        bool right = false, left = false;
        for (int i = 0; i + ap < bp - i; i++) {
            if (a[i+ap] < a[bp-i]) {
                left = true;
                break;
            }
            if (a[i+ap] > a[bp-i]) {
                right = true;
                break;
            }
        }
        if (left) {
            cout << a[ap++];
        } else if (right) {
            cout << a[bp--];
        } else {
            cout << a[ap++];
        }
        newline++;
    }
    cout << endl;

    return 0;
}

