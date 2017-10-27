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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);
    while (n) {
        vector<string> data(n);
        rep(i, n) {
            cin >> data[i];
        }
        int less = -INF, more = INF;
        if (data[0][0] == 'x') {
            if ( data[1][0] == 'x' ) {
                cout << "none" << endl;
                cin >> n;
                continue;
            } else {
                more = stoll(data[1]) - 1;
            }
        } else {
            int b = (data[1][0] == 'x') ? INF : stoll(data[1]);
            if (!(b > stoll(data[0]))) {
                cout << "none" << endl;
                cin >> n;
                continue;
            }
        }
        bool fl = false;
        Rep(i, n-1) {
            if (data[i][0] == 'x') {
                if ((i+1) % 2) {
                    if (data[i+1][0] == 'x') {
                        fl = true;
                        break;
                    } else {
                        more = min(more, 
                                min(stoll(data[i-1])-1,
                                    stoll(data[i+1])-1));
                    }
                } else {
                    if (data[i+1][0] == 'x') {
                        fl = true;
                        break;
                    } else {
                        less = max(less, 
                                max(stoll(data[i-1])+1,
                                    stoll(data[i+1])+1));
                    }
                }
            } else {
                if ((i+1) % 2) {
                    int a = (data[i-1][0] == 'x') ? INF : stoll(data[i-1]);
                    int b = (data[i+1][0] == 'x') ? INF : stoll(data[i+1]);
                    if (!(a > stoll(data[i]) && b > stoll(data[i]))) {
                        fl = true;
                        break;
                    }
                } else {
                    int a = (data[i-1][0] == 'x') ? -INF : stoll(data[i-1]);
                    int b = (data[i+1][0] == 'x') ? -INF : stoll(data[i+1]);
                    if (!(a < stoll(data[i]) && b < stoll(data[i]))) {
                        fl = true;
                        break;
                    }
                }
            }
        }
        if (fl) {
            cout << "none" << endl;
            cin >> n;
            continue;
        }
        if (data[n-1][0] == 'x') {
            if (n % 2) {
                more = min(more, stoll(data[n-2])-1);
            } else {
                less = max(less, stoll(data[n-2])+1);
            }
        } else {
            if ((n) % 2) {
                int a = (data[n-2][0] == 'x') ? INF : stoll(data[n-2]);
                if (!(a > stoll(data[n-1]))) {
                    cout << "none" << endl;
                    cin >> n;
                    continue;
                }
            } else {
                int a = (data[n-2][0] == 'x') ? -INF : stoll(data[n-2]);
                if (!(a < stoll(data[n-1]))) {
                    cout << "none" << endl;
                    cin >> n;
                    continue;
                }
            }
        }
        if (less == more) {
            cout << less << endl;
        } else if (less < more) {
            cout << "ambiguous" << endl;
        } else {
            cout << "none" << endl;
        }
        cin >> n;
    }

    return 0;
}

