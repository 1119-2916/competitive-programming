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
    int2(k, n);

    while (n != -1) {
        vi data(n);
        rep(i, n) {
            cin >> data[i];
        }
        sort(all(data));
        int ptr = 0, ans = 0;
        while (ptr < n) {
            //cout << "( " << ptr << ", ";
            int st = ptr, mid;
            for (int i = st; i < n && data[st] + k >= data[i]; i++) {
                mid = i;
            }
            for (int i = mid; i < n && data[mid] + k >= data[i]; i++) {
                ptr = i;
            }
            ptr++;
           // cout << mid << ", " << ptr << ")" << endl;
            ans++;
        }
        cout << ans << endl;
        cin >> k >> n;
    }

    return 0;
}

