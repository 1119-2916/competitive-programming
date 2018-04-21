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

string data, bef;

bool check()
{
    if (bef == data) return false;
    if (data.size() <= 3) return false;
    return true;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> data;

    while (check()) {
        //cout << bef << endl;
        vb app(3, false);
        bef = data;
        data = "";
        int i = 0;
        for (i = 0; i < bef.size()-2; i++) {
            if (bef[i] == 'A' && bef[i+1] == 'B' && bef[i+2] == 'C') {
                data.pb('X');
                i += 2;
            } else {
                data.pb(bef[i]);
                app[bef[i] - 'A'] = true;
            }
        }
        for (; i < bef.size(); i++) {
            data.pb(bef[i]);
            app[bef[i]-'A'] = true;
        }

        //cout << data << endl;

        rep(i, app.size()) {
            if (!app[i]) {
                rep(j, data.size()) {
                    if (data[j] == 'X') data[j] = 'A' + i;
                }
                break;
            }
        }
        //cout << data << endl;
        //cout << "============" << endl;
    }

    cout << ((data == "ABC") ? "Yes" : "No") << endl;


    return 0;
}








