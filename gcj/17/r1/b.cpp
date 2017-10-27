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
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(dataset);
    Rep(state, dataset+1) {
        cout << "Case #" << state << ": ";

        int2(a,b);

        if (a + b == 1) {
            int2(st, en);
            cout << 2 << endl;
        } else if (!a || !b) {
            int2(st1, en1);
            int2(st2, en2);
            if (st2 < st1) {
                int tmp = st1;
                st1 = st2; st2 = tmp;
                tmp = en1;
                en1 = en2; en2 = tmp;
            }
            if (en2 - st1 <= 720 ||
                    st2 - en1 >= 720) {
                cout << 2 << endl;
            } else {
                cout << 4 << endl;
            }
        } else {
            int2(st1, en1);
            int2(st2, en2);
            cout << 2 << endl;
        }
    }


    return 0;
}

