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
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

void board(int rank)
{
    if (rank) {
        rep(i, 9) {
            board(rank-1);
            rep(j, 9) {
                if (j == i) {
                    std::cout << "#";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    } else {
        //cout << endl;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    /*
    int st = 7;
    int n = 9;
    rep(i, n) {
        rep(j, n) {
            if (j == st || (st < 3 && (st+7) % 9 == j)) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        st = (st + 2) % 9;
        cout << endl;
    }
    */
    board(9);

    return 0;
}



