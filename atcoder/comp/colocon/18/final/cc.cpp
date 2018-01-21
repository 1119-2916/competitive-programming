#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<i_i> data(n);
    vi ans(n, INF);
    for (int i = 0; i < n; i++) {
        cin >> data[i].fir;
        data[i].fir *= -1;
        data[i].sec = i;
        ans[i] = -data[i].fir;
    }
    sort(all(data));
    rep(i, n) data[i].fir *= -1;
    //rep(i, n) cout << data[i] << " "; cout << endl;

    rep(i, n) {
        int ptr = data[i].sec;
        //ans[ptr] = min(ans[ptr], data[i].fir);
        //int cnt = 0;
        for (int j = ptr+1; j < n; j++) {
            ///*
            if (data[i].fir + (j-ptr)*(j-ptr) < ans[j]) {
                ans[j] = data[i].fir + (j-ptr)*(j-ptr);
            } else {
                //cnt++;
                //if (cnt > 100) break;
            }
            //*/
            //ans[j] = min(ans[j], data[i].fir + (j-ptr)*(j-ptr));
        }
        cnt = 0;
        for (int j = ptr-1; j >= 0; j--) {
            ///*
            if (data[i].fir + (ptr-j)*(ptr-j) < ans[j]) {
                ans[j] = data[i].fir + (ptr-j)*(ptr-j);
            } else {
                cnt++;
                if (cnt > 100) break;
            }
            //*/
            //ans[j] = min(ans[j], data[i].fir + (ptr-j)*(ptr-j));
        }
        //rep(i, n) cout << ans[i] << " "; cout << endl;
    }
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }


    return 0;
}

