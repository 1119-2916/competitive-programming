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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

class ImageCompression {

    public:
    string isPossible(vector <string> image, int k) {

        bool ret = true;

        rep(i, image.size()) {
            for (int j = 0; j + k <= image[i].size(); j += k) {
                char p = image[i][j];
               // cout << i << " " << j << endl;
                rep(l, k) {
                    if (p != image[i][j+l]) {
                  //      cout << i << " " << j + l << endl;
                        ret = false;
                    }
                }
            }
        }
       // cout << ret << endl;

        rep(j, image[0].size()) {
            for (int i = 0; i + k <= image.size(); i += k) {
                char p = image[i][j];
                rep(l, k) {
                    if (p != image[i+l][j]) {
                        ret = false;
                    }
                }
            }
        }

        return (ret) ? "Possible" : "Impossible";
    }
};

 
signed main()
{
    ImageCompression im;

    vector<string> st;
    int n; cin >> n;
    rep(i, n) {
        string tmp;
        cin >> tmp;
        st.pb(tmp);
    }
    int k; cin >> k;
    cout << im.isPossible(st, k) << endl;



    return 0;
}

