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
    int table[14] = {0, 13, 1, 2, 3, 
        4, 5, 6, 7, 8,
        9, 10, 11, 12};

    Int(a);
    Int(b);

    if (table[a] < table[b]) {
        cout << "Bob" << endl;
    } else if (table[a] == table[b]) {
        cout << "Draw" << endl;
    } else {
        cout << "Alice" << endl;
    }


    return 0;
}

