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

int mmnmm(int num)
{
    int bit = 0;
    int nnum = num;
    while (num) {
        bit++;
        num /= 2;
    }
    return (1LL << bit) - nnum;
}

int find(vi &data, int targ)
{
    if (data.back() == targ) return data.size()-1;
    if (data[0] == targ) return 0;
    int left = 0, right = data.size()-1;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (data[mid] < targ) {
            left = mid;
        } else if (data[mid] > targ) {
            right = mid;
        } else {
            return mid;
        }
    }
    if (data[right] == targ) return right;
    else if (data[left] == targ) return left;
    else return -1;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    map<int, int> funami;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        funami[data[i]]++;
    }
    sort(all(data)); reverse(all(data));

    int ans = 0;
    rep(i, n) {
        if (funami[data[i]]) {
            funami[data[i]]--;
            int targ = mmnmm(data[i]);
            //std::cout << targ;
            if (funami[targ]) {
                funami[targ]--;
                ans++;
                //cout << " yes ";
            }
            //cout << endl;
        }
    }
    std::cout << ans << std::endl;

    /*
    sort(all(data));
    vi used(n, 0);

    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (!used[i]) {
            int targ = mmnmm(data[i]);
            int yui = find(data, targ);
            std::cout << targ << " " << yui << std::endl;
            if (yui != -1) {
                ans++; 
                used[yui] = 1;
            }
        }
    }

    std::cout << ans << std::endl;
    */

    return 0;
}
