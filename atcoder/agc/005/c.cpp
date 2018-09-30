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
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    if (n == 2) {
        if (data[0] == data[1] && data[0] == 1) {
            std::cout << "Possible" << std::endl;
        } else {
            std::cout << "Impossible" << std::endl;
        }
        return 0;
    }

    vector<int> funami(n, 0);
    rep(i, data.size()) {
        funami[data[i]]++;
    }

    int left, right;
    rep(i, funami.size()) {
        if (funami[i]) {
            left = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (funami[i]) {
            right = i;
            break;
        }
    }

    if (funami[left] > 1) {
        if (funami[left] > 2) {
            std::cout << "Impossible" << std::endl;
            return 0;
        }
        if (right != left * 2 - 1) {
            std::cout << "Impossible" << std::endl;
            return 0;
        }
        for (int i = left; i < right; i++) {
            if (funami[i] < 2) {
                std::cout << "Impossible" << std::endl;
                return 0;
            }
        }
        std::cout << "Possible" << std::endl;
        return 0;
    }

    if (left * 2 != right) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }

    for (int i = left; i < right+1; i++) {
        if (!funami[i]) {
            std::cout << "Impossible" << std::endl;
            return 0;
        }
    }

    if (funami[left] > 1) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }

    for (int i = left+1; i < right+1; i++) {
        if (funami[i] <= 1) {
            std::cout << "Impossible" << std::endl;
            return 0;
        }
    }
    std::cout << "Possible" << std::endl;

    return 0;
}
