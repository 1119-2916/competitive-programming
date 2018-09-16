#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define int long long
#define fir first
#define sec second

signed main(void)
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, string>> input;
        rep(i, n) {
            string st;
            int num;
            cin >> st >> num;
            input.push_back(make_pair(num, st));
        }
        stack<pair<int, string>> funami;

        while (input.size()) {
            vector<pair<int, string>> nxt;
            rep(i, input.size()) {
                if (!funami.empty()) {
                    if (funami.top().sec == input[i].sec) {
                        input[i].fir += funami.top().fir;
                        funami.pop();
                    }
                }
                if (input[i].fir / 3) 
                nxt.push_back(make_pair(input[i].fir / 3, input[i].sec));

                if (input[i].fir % 3)
                funami.push(make_pair(input[i].fir % 3, input[i].sec));
            }
            input = nxt;
        }
        int ans = 0;
        while (!funami.empty()) {
            ans += funami.top().fir;
            funami.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
