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
 
bool cross(int a, int b);

signed main()
{
    string input;
    while (cin >> input, input[0] != '#') {
        int lc = 0, rc = 0, ll, lr, rl, rr;
        rep(i, input.length()) {
            if (!i) {
                ll = input[0];
                continue;
            }
            if ((i+lc) % 2) {
                if (cross(ll - '0', input[i] - '0')) {
                    lc++;
                    ll = input[i];
                } else {
                    lr = input[i];
                }
            } else {
                if (cross(input[i] - '0', lr - '0')) {
                    lc++;
                    lr = input[i];
                } else {
                    ll = input[i];
                }
            }
        }
        rep(i, input.length()) {
            if (!i) {
                rr = input[0];
                continue;
            }
            if ((i+rc) % 2) {
                if (cross(input[i] - '0', rr - '0')) {
                    rc++;
                    rr = input[i];
                } else {
                    rl = input[i];
                }
            } else {
                if (cross(rl - '0', input[i] - '0')) {
                    rc++;
                    rl = input[i];
                } else {
                    rr = input[i];
                }
            }
        }
        cout << min(lc, rc) << endl;
    }
    return 0;
}

bool cross(int a, int b)
{
    if (!(a % 3)) {
        if (b % 3) {
            return true;
        } else {
            return false;
        }
    } else if ((a % 3) == 2) {
        if (b % 3 == 1) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}



