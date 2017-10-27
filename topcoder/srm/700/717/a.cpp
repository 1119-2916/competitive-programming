#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%d", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign


class NiceTable1 {

    public :
        string isNice(vector <string> t)
        {
            int size = t.size();
            int lengthStr = t[0].length();
            int flag;
            for (int i = 0; i < lengthStr; i++) {
                for (int j = 0; j < size; j++) {
                    flag = 1;
                    for (int m = 0; m < size; m++) {
                        for (int n = 0; n < lengthStr; n++) {
                            if ((t[m][n] - '0') != ((t[m][i] - '0')
                                        ^
                                        (t[j][n] - '0'))) {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    if (flag == 1) {
                        return "Nice";
                    }
                }
            }
            return "Not nice";
        }
};

class NiceTable {

    public :
        string isNice(vector <string> t)
        {
            bool ans = false;
            rep(a, (1 << t.size())) {
                rep(b, (1 << t[0].size())) {
                    bool isok = true;
                    rep(i, t.size()) {
                        rep(j, t[0].size()) {
                            int num = (!!((a & (1 << i)))^
                                    (!!(b & (1 << j))));
                            num = (num) ? 1 : 0;
                            if ((t[i][j] - '0') != num) {
                                isok = false;
                            }
                        }
                    }
                    ans |= isok;
                }
            }
            if (ans) {
                return "Nice";
            } else {
                return "Not nice";
            }
        }
};

 
signed main()
{
    NiceTable nc;
    NiceTable1 nc1;

    Int(n);
    vector<string> input(n);
    rep(i, n) {
        cin >> input[i];
    }
    if (nc.isNice(input) != nc1.isNice(input)) {
        cout << "koreda" << endl;
    }
    cout << nc1.isNice(input) << endl;

    return 0;
}

