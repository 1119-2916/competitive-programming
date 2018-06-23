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

    Int(data);
    while (data--) {
        int2(n, m);
        vector<int> data(n);
        bool ret = false;
        for (int i = 0; i < n; i++) {
            cin >> data[i];
            ret |= (data[i] >= m);
        }
        if (ret) {
            cout << 1 << endl;
            continue;
        } else if (m <= 0) {
            cout << -1 << endl;
            continue;
        }

        int sum = 0, left = 0, ans = INF;
        for (int i = 0; i < n; i++) {
            sum += data[i];
            //cout << left << " " << sum << endl;
            if (sum >= m) {
                while (sum >= m && i >= left) {
                    ans = min(ans, i - left + 1);
                    sum -= data[left++];
                }
                int tmp = sum;
        //        cout << "call : ";
                for (int j = left-1; j <= i; j++) {
         //           cout << tmp << " ";
                    tmp -= data[j];
                    if (tmp >= m) ans = min(ans, i - j);
                }
          //      cout << endl;
            } else if (sum <= 0) {
                left = i+1;
                sum = 0;
            }
        }

        if (ans != INF) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }

    }


    return 0;
}



