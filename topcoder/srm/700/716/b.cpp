#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
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
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%d", &x);
#define int2(x, y) int x, y; scanf("%d %d", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

class ConstructLCSEasy
{
    public:
        string construct(int ab, int bc, int ca)
        {
            string A, B, C, s;
            rep(i, ca) {
                s += '1';
            }
            s += ' ';
            rep(i, ab) {
                s += '1';
            }
            rep(i, bc-ab) {
                s += '0';
            }
            s += ' ';
            rep(i, ca) {
                s += '1';
            }
            rep(i, ca) {
                s += '0';
            }
            return s;
            /*
            rep(i, ca-ab) {
                A.pb('1');
                C.pb('1');
            }
            rep(i, ab) {
                A.pb('0');
                B.pb('0');
                C.pb('0');
            }
            rep(i, bc-ab) {
                B.pb('1');
                C.pb('1');
            }
            */
            return A + " " + B + " " + C;
        }

};

 
signed main()
{
    ConstructLCSEasy yui;

    int2(a, b);
    Int(c);
    cout << yui.construct(a, b, c) << endl;

    return 0;
}

