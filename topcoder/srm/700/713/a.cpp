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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%d %d", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign


class SymmetryDetection{

    public:
   string detect(vector <string> board) {

       bool ii = true, jj = true;
       rep(i, board.size() / 2) {
           rep(j, board[0].size()) {
               if (board[i][j] != board[board.size()-i-1][j]) {
                   ii = false;
                   break;
               }
           }
       }
       rep(j, board[0].size() / 2) {
           rep(i, board.size()) {
               if (board[i][j] != board[i][board[0].size()-j-1]) {
                   jj = false;
                   break;
               }
           }
       }

       if (jj && ii) {
           return "Both";
       } else if (jj) {
           return "Vertically";
       } else if (ii) {
           return "Horizontally";
       } else {
           return "Neither";
       }
   };

};

int main()
{
    int2(n, m);
    vector<string> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    SymmetryDetection p;

    cout << p.detect(a) << endl;

    return 0;
}

        



