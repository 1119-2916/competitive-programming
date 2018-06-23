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

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(data);
    while (data--) {
        map<string, int> funami;
        Int(n);
        rep(i, n) {
            string st;
            cin >> st;
            funami[st]++;
        }
        if (funami.size() == 0) cout << "Draw" << endl;
        else if (funami.size() == 1) cout << funami.begin()->fir << endl;
        else {
            auto back = funami.end(); back--;
            //cout << funami.begin()->fir << " " << funami.begin()->sec
             //   << endl;
            //cout << back->fir << " " << back->sec << endl;
            if (funami.begin()->sec == back->sec)
                cout << "Draw" << endl;
            else if (funami.begin()->sec < back->sec) 
                cout << back->fir << endl;
            else cout << funami.begin()->fir << endl;
        }
    }


    return 0;
}
