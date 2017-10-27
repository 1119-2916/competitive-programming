#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++) 
#define MOD 1000000007

typedef pair<int, int> i_i;
typedef long long int llint;

int getBit(llint a);
llint refBits(llint a, llint u);

int main()
{
    llint le, ans = 0, bef = 0;
    cin >> le;
    le++;

    rep(n, le) {
        cout << n << " ";
    rep(i, n) {
        rep(j, n) {
            rep(k, j+1) {
                if (k - i == refBits(k, j)) {
                    ans++;
                    ans %= MOD;
                }
            }
        }
    }
    cout << ans - bef << endl;
    bef = ans;
    }

    return 0;
}

int getBit(llint a)
{
    int ans = 0;
    while (a) {
        a /= 2;
        ans++;
    }
    return ans;
}

/*
 * a xor b = u を移項した
 * a ??? u = @return を求める関数
 */
llint refBits(llint a, llint u)
{
    llint ret = 0;
    int lp = getBit(u);
    for (int i = 0; i < lp; i++) {
        if (u & 1<<i) {
            if (!(a & 1<<i)) {
                ret += 1<<i;
            }
        } else {
            ret += (a & 1<<i);
        }
    }
    return ret;
}
