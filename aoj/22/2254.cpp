#include <iostream>
#include <algorithm>
#define INF 1010001000

using namespace std;

int dp[(1 << 16)], n;

int main() 
{
    while (cin >> n, n) {
        int noitem[n], input[n][n];
        for (int i = 0; i < n; i++) {
            cin >> noitem[i];
            for (int j = 0; j < n; j++) {
                cin >> input[i][j];
            }
        }
        for (int i = 0; i < (1 << n); i++) {
            dp[i] = INF;
        }
        dp[0] = 0;

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (!((i>>j) & 1)) {
                    dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i]+noitem[j]);
                    for (int k = 0; k < n; k++) {
                        if ((i >> k) & 1) {
                            dp[i|(1<<j)] = min(dp[i|(1<<j)],
                                    dp[i] + input[j][k]);
                        }
                    }
                }
            }
        }
        cout << dp[(1 << n) -1] << endl;
    }
    return 0;
}
