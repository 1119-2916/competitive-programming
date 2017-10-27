#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
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
#define Edge pair< int, i_i >
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

int state[1000002];

signed main()
{
    // 入力
    Int(n);
    vector< pair< i_i, int > > data(n);
    rep(i, n) {
        cin >> data[i].ffir >> data[i].fsec;
        data[i].sec = i;
        state[data[i].ffir]++; state[data[i].fsec+1]--;
    }

    // 小屋数探し
    int ret = state[0];
    Rep(i, 1000002) {
        state[i] += state[i-1];
        ret = max(ret, state[i]);
    }
    cout << ret << endl;

    // solve
    int ptr = 1;
    sort(all(data));
    vi ans(n);
    priority_queue< i_i > funami;
    rep(i, data.size()) {
        if (funami.empty()) {
            ans[data[i].sec] = ptr;
            //cout << ptr << endl;
            funami.push(i_i(-data[i].fsec, ptr++));
        } else if (-funami.top().fir < data[i].ffir) {
            int tmp = funami.top().sec; funami.pop();
            ans[data[i].sec] = tmp;
            //cout << tmp << endl;
            funami.push(i_i(-data[i].fsec, tmp));
        } else {
            ans[data[i].sec] = ptr;
            //cout << ptr << endl;
            funami.push(i_i(-data[i].fsec, ptr++));
        }
        //cout << "queue :" << -funami.top().fir << endl;
    }
    rep(i, n) cout << ans[i] << endl;

    return 0;
}




