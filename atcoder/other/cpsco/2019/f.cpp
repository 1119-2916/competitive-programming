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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
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
    vector<pair<int, pii>> data(n);
    int left = -INF, right = 100100010001000;
    rep(i, n) {
        cin >> data[i].fir >> data[i].sfir >> data[i].ssec;
        //left = min(data[i].sfir - abs(i - data[i].fir) * data[i].ssec, left);
        right = min(right, data[i].sfir + 1);
    }

    vp ecasdqina(n);
    while (right - left > 1) {
        int mid = (right + left) / 2;
        //std::cout << left << " " << right << " " << mid << std::endl;
        rep(i, n) {
            ecasdqina[i].fir = data[i].fir - max(0ll, (data[i].sfir - mid) / data[i].ssec);
            ecasdqina[i].sec = data[i].fir + max(0ll, (data[i].sfir - mid) / data[i].ssec);
        }
        sort(all(ecasdqina));
        //rep(i, n) { std::cout << ecasdqina[i].fir << " " << ecasdqina[i].sec << endl; }
        int p = 0;
        priority_queue<int> pq;
        while (p < n && ecasdqina[p].fir <= 1) {
    //std::cout << "push : " << -ecasdqina[p].sec << std::endl;
            pq.push(-ecasdqina[p].sec);
            p++;
        }
        bool res = true;
        Rep(i, n+1) {
            while (pq.size() && -pq.top() < i) {
        //std::cout << "pop : " << pq.top() << std::endl;
                pq.pop();
            }
            while (p < n && ecasdqina[p].fir <= i) {
        //std::cout << "push : " << -ecasdqina[p].sec << std::endl;
                pq.push(-ecasdqina[p].sec);
                p++;
            }
            if (pq.size()) {
        //std::cout << "pop : " << pq.top() << std::endl;
                pq.pop();
            } else {
                res = false;
            }
        }
        if (res) {
            left = mid;
        } else {
            right = mid;
        }
    }

    std::cout << left << std::endl;

    return 0;
}
