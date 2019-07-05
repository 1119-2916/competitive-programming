#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define int long long

string fix(string &st, int keta)
{
    if (keta < 0) assert(0);
    if (st.size() == 0) return "";
    if (keta > 55) {
        string ret = "";
        rep(i, st.size()) {
            ret += "0";
        }
        return ret;
    } else {
        string ret = "";
        rep(i, keta) {
            ret += "0";
        }
        ret += st;
        return ret.substr(0, st.size());
    }
}

string addst(const string &lst, const string &sst, int *crr)
{
    //cout << "lst : " << lst << endl;
    //cout << "sst : " << sst << endl;
    if (sst == "") return lst;
    if (sst.size() != lst.size()) {
        cout << sst << endl << lst << endl;
        assert(0);
    }

    *crr = (lst[0] == '1' && sst[0] == '1');
    int ctmp = 0;
    string ret;
    for (int i = lst.size()-1; i >= 0; i--) {
        int cnt = ctmp + (int)(lst[i] == '1') + (int)(sst[i] == '1');
        ret.push_back(('0'+(cnt%2)));
        ctmp = cnt & 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void _solve(int n, int pketa, string st, int *keta, string &ans)
{
    /*
    cout << "call : " << n << '\n' << st << '\n'
        << ans << endl <<
        "~~~~~~~~~" << endl;;
    */
    if (!n) {
        return;
    }

    //cout << pketa << " " << *keta << endl;
    if (n % 2) {
        int tmp = 0;
        if (pketa >= *keta) {
            ans = addst(st, fix(ans, pketa - *keta), &tmp);
            *keta = pketa + tmp;
        } else {
            ans = addst(ans, fix(st, *keta - pketa), &tmp);
            *keta = *keta + tmp;
        }
    }
/*
    cout << pketa << '\n' << 
        "power  : " << st << '\n' << 
        *keta << '\n' << 
        "answer : " << ans << endl <<
        "~~~~~~~~~~" << endl;
*/
    int crr = 0;
    string nxt = addst(st, st, &crr);
    pketa += crr;

    _solve(n/2, pketa, st, keta, ans);
}


void solve(int n, string &st)
{
    int keta = 0;
    string ans;
    _solve(n, 0, "1" + st, &keta, ans);
    string hoge;
    //while (keta) {
    rep(i, 12) {
        hoge += (keta % 2 ? "1" : "0");
        keta /= 2;
    }
    if (keta) assert(0);
    reverse(hoge.begin(), hoge.end());
    //cout << hoge << ans << endl;
    cout << hoge;
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
}

signed main()
{
    int n;
    while (cin >> n, n) {
        string st;
        cin >> st;
        solve(n+1, st);
    }
    return 0;
}
