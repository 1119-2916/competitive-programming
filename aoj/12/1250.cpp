#include <bits/stdc++.h>
 
using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
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
#define all(a) (a).begin(), (a).end()
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int n;
    cin >> n;
    rep(loop, n) {
        vector< unsigned int > input(8);
        unsigned int key;
        rep(i, 8) {
            scanf("%x", &input[i]);
        }
        scanf("%x", &key);
        unsigned int ans = 0, keta = 0;

        while (keta < 33) {
            unsigned int tmp = 0;
            rep(i, 8) {
                tmp += input[i];
            }
            if ( (((tmp >> keta)%2)+((key >> keta)%2)) % 2 ) {
                rep(i, 8) {
                    input[i] ^= (1 << keta);
                }
                ans |= (1 << keta);
            }
            keta++;
        }
        printf("%x\n", ans);
    }
    return 0;
}

