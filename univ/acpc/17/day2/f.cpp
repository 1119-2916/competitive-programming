#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define int long long 
#define rep(i, N) for (int i = 0; i < N; i++)
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define vi vector<int>
#define vvi vector< vi >

string funami_yui(int n)
{
    string ret;
    while (n) {
        ret.push_back((n % 2) + '0');
        n /= 2;
    }
    //reverse(ret.begin(), ret.end());
    return ret;
}


signed main()
{
    int n;
    cin >> n;

    string st = funami_yui(n);
//    cout << st << endl;

    rep(i, st.size()) {
        if (st[i] == '0') {
            std::cout << (int)pow(2LL, i) << std::endl;
            //printf("%lld\n", (int)pow(2LL, i)); 
            return 0;
        }
    }
    std::cout << (int)pow(2LL, st.size()) << std::endl;
    //printf("%lld\n", (int)pow(2LL, st.size())); 

    return 0;
}
