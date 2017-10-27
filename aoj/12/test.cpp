#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 111;
const int MAXT = 111;
int N, T, L, B;
int G[MAXN];
double dp[MAXT][MAXN];
 
int main() {
  while(cin >> N >> T >> L >> B && (N|T|L|B)) {
    memset(G, 0, sizeof(G));
    for(int i = 0; i < L; ++i) {
      int Lose; cin >> Lose;
      G[Lose] = 1;
    }
    for(int i = 0; i < B; ++i) {
      int Back; cin >> Back;
      G[Back] = 2;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1.0;
    for(int i = 0; i < T; ++i) {
      for(int j = 0; j <= N; ++j) {
        if(j == N) {
          dp[i+1][j] += dp[i][j];;
          continue;
        }
        for(int k = 1; k <= 6; ++k) {
          int nj = j + k <= N ? j + k : N - (k - (N - j));
          int ni = i + 1;
          if(G[nj] == 1) ++ni;
          else if(G[nj] == 2) nj = 0;
          dp[ni][nj] += dp[i][j] / 6.0;
        }
      }
    }
    printf("%.10f\n", dp[T][N]);
  }
  return 0;
}
