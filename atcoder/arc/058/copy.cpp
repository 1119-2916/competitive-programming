#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

#define mod 1000000007

ll add(ll x, ll y){
    return (x+y)%mod;
}

ll mul(ll x, ll y){
    return (x%mod)*(y%mod)%mod;
}

ll powll(ll x, ll y){
    ll res = 1LL;
    while(y){
        if (y & 1LL)
            res *= x;
        res %= mod;
        x = (x*x) % mod;
        y >>= 1LL;
    }
    return res;
}

ll divll(ll x, ll y){
    return (x * powll(y,mod-2)) % mod;
}

string bitst(int i)
{
    string st;
    if (!i) return "0";
    while (i) {
        st.push_back(i % 2 + '0');
        i /= 2;
    }
    reverse(st.begin(), st.end());
    return st;
}

ll dp[41][1<<17];

int main(void){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int m = x + y + z;

    ll xyz = (1<<(x+y+z-1)) + (1<<(y+z-1)) + (1<<(z-1));

    dp[0][0] = 1;
    REP(i,n) REP(mask,1<<m){
        FOR(k,1,10){
            int next = (mask << k) + (1 << (k-1));
            next &= (1<<m) - 1;
            if ((next & xyz) == xyz) continue;
            dp[i+1][next] = (dp[i+1][next] + dp[i][mask]) % mod; 
        }
    }
    for (int i = 0; i < 1<<17; i++) {
        if (dp[n][i]) 
            cout << bitst(i) << " " << dp[n][i] << endl;
    }
    ll ans = 0;
    REP(mask,1<<m) ans = (ans + dp[n][mask]) % mod;
    ans = (powll(10,n) - ans + mod) % mod;
    cout << ans << endl;

    return 0;
}
