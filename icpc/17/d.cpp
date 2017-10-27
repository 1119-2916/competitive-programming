#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define vi vector< int > 
#define vvi vector< vi >

int n, m;

string bitxor(string a, string b)
{
    string ret;
    rep(i, min(a.size(), b.size())) {
        ret.pb( (a[i] == b[i]) ? '0' : '1');
    }
    return ret;
}

int parse(string a)
{
    int ret = 0, pow = 1;
    for (int i = a.size()-1; i >= 0; i--) {
        ret += pow * (a[i] - '0');
        pow *= 2;
    }
    return ret;
}

bool zero_string(string st)
{
    rep(i, st.size()) {
        if (st[i] != '0') {
            return false;
        }
    }
    return true;
}

int main()
{
    for (; cin >> n >> m && n;) {
        vector<string> input(n);
        rep(i, n)cin >> input[i];

        if (n <= 30) {
        //if (0) {
            map< string, int > data;
            int n2 = n / 2;
            //cout << "data " << (1 << n2) << endl;
            rep(i, 1 << n2) {
                string state(m, '0');
                int cnt = 0;
                rep(j, n2) {
                    if (i&(1 << j)) {
                        state = bitxor(input[j], state);
                        cnt++;
                    }
                }
                //cout << state << " " << cnt << endl;
                data[state] = max(data[state], cnt);
            }
            int ans = 0;
            //cout << "data " << n - n2 << endl;
            rep(i, 1 << (n - n2)) {
                string state(m, '0'); int cnt = 0;
                rep(j, n - n2) {
                    if (i&(1 << j)) {
                        state = bitxor(input[j + n2], state);
                        cnt++;
                    }
                }
                //cout << state << " " << cnt << endl;
                if (data[state] || (cnt && zero_string(state))) {
                    ans = max(ans, data[state] + cnt);
                }

            }
            cout << ans << endl;
        } else {
            vi item(n);
            rep(i, n) {
                item[i] = parse(input[i]);
            //    cout << item[i] << endl;
            }
           // cout << (1 << m) << endl;
            vvi table(n+1, vi((1 << m), 0));
            rep(i, n) {
                for (int j = table[i].size()-1; j >= 0; j--) {
                    if (table[i][j]) {
                        table[i+1][j^item[i]] =
                            max(table[i+1][j^item[i]], table[i][j] + 1);
                        table[i+1][j] = max(table[i+1][j], table[i][j]);
                    }
                }
                table[i+1][item[i]] = max(table[i+1][item[i]], 1);
                /* 
                rep(j, table[i].size()) {
                    cout << table[i+1][j] << " ";
                }cout << endl;
                */ 
            }
            cout << table[n][0] << endl;
        }
    }
    return 0;
}
