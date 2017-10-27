#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; i++) 

using namespace std;

int main()
{
    int n;
    while (cin >> n, n) {
        int w, h;
        cin >> w >> h;
        vector<vector<bool> > board(w+1, vector<bool>(h+1, false));
        rep(i, n) {
            int a, b;
            cin >> a >> b;
            board[a][b] = true;
        }
        int a, b, ans = 0;
        cin >> a >> b;
        rep(i, w+2-a) {
            rep(j, h+2-b) {
                int cnt = 0;
                rep(k, a) {
                    rep(l, b) {
                        if (board[k+i][l+j]) {
                            cnt++;
                        }
                    }
                }
                ans = max(ans, cnt);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

