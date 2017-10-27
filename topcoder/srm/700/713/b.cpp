#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-10
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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

class PowerEquationEasy {

    public:

        int loggg(int k, int n) {
            int tmp = 1, cnt = 0;
            rep(i, n) {
                tmp *= k;
                if (tmp > n) {
                    break;
                }
                cnt++;
            }
            return cnt;
        }

        int count(int n) {

            vi T(n+1);
            Rep(i, n+1) {
                T[i] = loggg(i, n);
                cout << T[i] << endl;
            }
            long long int ans = 0;
            ans += (n * n) % MOD;
            ans += (n-1) * n % MOD;
            cout << ":" << ans << endl;
            for (int i = 2; i < n+1; i++) {
                for (int j = 2; j < T[i] +1; j++) {
                    cout << (T[i]/j) + (T[i]/j) << endl;
                    ans += (T[i]/j) + (T[i]/j);
                    ans %= MOD;
                }
            }
            return ans;
        }
};


int main()
{
    int n;
    cin >> n;
    PowerEquationEasy p;

    cout << p.count(n) << endl;

    return 0;
}


