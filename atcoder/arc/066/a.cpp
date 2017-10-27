#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++) 
#define MOD 1000000007

typedef pair<int, int> i_i;
typedef long long int llint;

int main()
{
    int n;
    cin >> n;
    vector<int> data(n, 0);
    rep(i, n) {
        int tmp;
        cin >> tmp;
        data[tmp]++;
    }
    llint ans = 1;
    if (n % 2) {
        if (data[0] != 1) {
            cout << "0" << endl;
            return 0;
        }
        for (int i = 2; i < n; i+=2) {
            if (data[i] != 2) {
                cout << "0" << endl;
                return 0;
            }
        }
        rep(i, n/2) {
            ans *= 2;
            ans %= MOD;
        }
    } else {
        for (int i = 1; i < n; i+=2) {
            if (data[i] != 2) {
                cout << "0" << endl;
                return 0;
            }
        }
        rep(i, n/2) {
            ans *= 2;
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
