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

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n);
    vector<map<int, int>> ecasdqina(n+1);
    ecasdqina[0][1] = 0;
    ecasdqina[0][2] = 0;
    ecasdqina[0][3] = 0;
    ecasdqina[0][4] = 0;
    ecasdqina[0][5] = 0;
    ecasdqina[0][6] = 0;
    ecasdqina[0][7] = 0;
    ecasdqina[0][8] = 0;
    ecasdqina[0][9] = 0;
    ecasdqina[0][10] = 0;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        ecasdqina[0][data[i]] = 0;
    }

    rep(i, n) {
        for (auto j : ecasdqina[i]) {
            ecasdqina[i+1][j.fir] = max(ecasdqina[i+1][j.fir], j.sec);
            if (j.fir <= data[i]) {
                ecasdqina[i+1][data[i]/j.fir] = max(ecasdqina[i+1][data[i]/j.fir], j.sec + data[i]/j.fir);
            }
        }
    }
/*
    rep(i, n+1) {
        cout << i << " : " << endl;
        for (auto j : ecasdqina[i]) {
            cout << j.fir << " " << j.sec << endl;
        }
    }
*/
    int ans = -1;
    for (auto i : ecasdqina[n]) {
        ans = max(ans, i.sec);
    }

    std::cout << ans << std::endl;


    return 0;
}




