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
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
// cmd

bool check(vvi &table, int x, int y)
{
    for (int i = 0; i < 9; i++) {
        if (!table[x+dx[i]][y+dy[i]]) return false;
    }
    return true;
}

void solve()
{
    Int(a);
    vvi table(40, vi(50, 0));
    int output[4][2] = {{2, 2}, {2, 3}, {4, 2}, {4, 3}};
    int output_index = 0;
    cout << output[output_index][0] << " " 
        << output[output_index][1] << endl;
    int x, y;
    while (cin >> x >> y, x > 0 && y > 0) {
        table[x-1][y-1] = 1;
        if (check(table, output[output_index][0]-1, 
                    output[output_index][1]-1)) {
            output_index++;
        }
        if (output_index == 4) return;
        cout << output[output_index][0] << " " 
            << output[output_index][1] << endl;
    }
}

void test()
{
    solve();
}

signed main()
{
    //test(); return 0;

    Int(t);
    for (int _ = 1; _ <= t; _++) {
        solve();
    }

    return 0;
}



