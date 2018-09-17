#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++) 
#define Rep(i, n) for (int i = 1; i < n; i++) 

struct BIT
{
    vector<int> data;
    BIT(int sz)
    {
        data.assign(++sz, 0);
    }

    int sum(int k)
    {
        int ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return ret;
    }

    void add(int k, int x)
    {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
};


int repow(int x, int n, int mod = MOD)
{
    if (n == 0) return 1;
    int res = repow((x * x) % mod, n / 2, mod);
    if (n & 1) res = (res * x) % mod;
    return res;
}

signed main(void)
{
    string st;
    cin >> st;

    vector<int> ans(st.size(), 0);

    vector<int> ptr;
    vector<set<int>> funami(26);
    Rep(i, st.size()) {
        funami[st[i] - 'a'].insert(i);
    }

    //BIT toshino(st.size());
    vector<int> toshino(st.size(), 0);

    rep(i, st.size()) {
        for (auto j : funami[st[i]-'a']) {
            if (i < j && toshino[j-1] == i) {
                toshino[j] = i+1;
                funami[st[i]-'a'].erase(j);
            } else {
                funami[st[i]-'a'].erase(j);
            }
        }
    }

    //for (int i : ans) cout << i << " "; cout << endl;
    for (int i : toshino) cout << i; cout << endl;

    int yui = 0;
    rep(i, ans.size()) {
        int tmp = toshino[i];
        if (!tmp) {
            yui = (yui + repow(26, st.size() - i - 1)) % MOD;
        }
    }

    cout << (repow(26, st.size()) - yui + MOD) % MOD << endl;

    return 0;
}


