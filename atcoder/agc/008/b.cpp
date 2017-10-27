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
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define Edge pair< i_i, int>
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
 
signed main()
{
    int2(n, k);
    vi data(n);
    rep(i, n) {
        cin >> data[i];
    }

    vi sum(n, 0), posum(n, 0);
    sum[0] = data[0];
    posum[0] = (data[0] < 0) ? 0 : data[0];
    Rep(i, n) {
        sum[i] = sum[i-1] + data[i];
        posum[i] += posum[i-1] + ((data[i] < 0) ? 0 : data[i]);
    }
    /*
    rep(i, n) {
        std::cout << posum[i] << std::endl;
    }*/

    int ret = 0;
    rep(i, (n - k + 1)) {
      //  std::cout << "==========" << std::endl;
       // std::cout << "start" << i << std::endl;
        // kuro
        int tmp = 0;
        if (i) {
            tmp += posum[i-1];
        //    std::cout << "front: " << tmp << std::endl;
        }
        
       // std::cout << tmp << " ";
        tmp += posum[n-1] - posum[i + k - 1];
       // std::cout << "(" << i + k << "," << n-1 << ")  "
       //      << posum[n-1] - posum[i + k - 1] << std::endl;
        ret = max(ret, tmp);
        if (i) {
            ret = max(ret, tmp + sum[i + k - 1] - sum[i-1]);
        //    cout << sum[i + k - 1] - sum[i-1] << endl;
        } else {
            ret = max(ret, tmp + sum[i + k - 1]);
         //   cout << sum[i + k - 1] << endl;
        }
    }

    cout << ret << endl;
    return 0;
}

