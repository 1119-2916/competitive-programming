#include <iostream>
#include <string>

#define INF 110001000
 
int main()
{
    int n, m;
    std::cin >> n >> m;
    std::string st;
    std::cin >> st;
    int cost[26];

    for (int i = 0; i < n; i++) {
        std::string tmp;
        int a, b;
        std::cin >> tmp >> a >> b;
        cost[tmp[0]-'a'] = std::min(a, b);
    }

    static int dp[2001][2002];
    for (int i = 0; i < m+1; i++) {
        std::fill(&dp[i][0], &dp[i][m+1], INF);
        dp[i][i] = dp[i][i+1] = 0;
    }

    for (int len = 0; len < m; len++) {
        for (int i = 0; i < m; i++) {
            int j = i + len;
            if (0 < i) {
                dp[i-1][j] = 
                    std::min(dp[i-1][j], dp[i][j] + cost[st[i-1]-'a']);
            }
            if (j < m) {
                dp[i][j+1] = 
                    std::min(dp[i][j+1], dp[i][j] + cost[st[j]-'a']);
            }
            if (0 < i && j < m && st[i-1] == st[j]) {
                dp[i-1][j+1] = 
                    std::min(dp[i-1][j+1], dp[i][j]);
            }
        }
    }

    std::cout << dp[0][m] << std::endl;

    return 0;
}

