#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)

class StringTransform {

    public:
        string isPossible(string s, string t) {
            bool able[30];
            memset(able, false, sizeof(able));

            rep(i, s.size()) {
                able[s[i] - 'a'] = true;
                if (!able[t[i]-'a']) {
                    return "Impossible";
                }
            }

            return "Possible";
        }
};



