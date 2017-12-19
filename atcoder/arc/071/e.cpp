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

    string st1, st2;
    cin >> st1 >> st2;

    vector<i_i> data1(st1.size()+1), data2(st2.size()+1);
    rep(i, st1.size()) {
        if (st1[i] == 'A') {
            data1[i+1].fir++;
        } else {
            data1[i+1].sec++;
        }
    }
    rep(i, data1.size()-1) {
        data1[i+1].fir += data1[i].fir;
        data1[i+1].sec += data1[i].sec;
    }

    rep(i, st2.size()) {
        if (st2[i] == 'A') {
            data2[i+1].fir++;
        } else {
            data2[i+1].sec++;
        }
    }
    rep(i, data2.size()-1) {
        data2[i+1].fir += data2[i].fir;
        data2[i+1].sec += data2[i].sec;
    }
    

    Int(n);
    rep(i, n) {
        int2(a, b); int2(c, d);
        int yui = data1[b].sec - data1[a-1].sec +
                    (data1[b].fir - data1[a-1].fir) * 2;
        int kyoko = data2[d].sec - data2[c-1].sec +
                    (data2[d].fir - data2[c-1].fir) * 2;
        if (yui % 3 == kyoko % 3) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }



    

    return 0;
}




