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

pii solve(vi &data, int p)
{
    int ptr = lower_bound(all(data), p) - data.begin();
    if (ptr != 0) {
        int diff = p - data[ptr];
        ptr = (data[ptr] - p < p - data[ptr-1]) ? ptr : ptr-1;
    }
    //cout << "ptr : " << ptr << endl;

    if (ptr == data.size()-1) {
        return {data.size()-1, data.size()-1-2}; // sente ga n ikou wo totte n-2 izenn wo 2 oki ni totta
    }

    int left = ptr, right = data.size()-1;
    while (right - left > 1) {
        int mid = (right + left) / 2; // mid wo torutoki
        int tak = data.size()-1 - mid;

        int inv = lower_bound(all(data), p - (data[mid] - p)) - data.begin();
        //if (data[inv] == p - (data[mid] - p)) inv--;
        int aok = mid - inv + 1;
        if (tak >= aok) {
            left = mid;
        } else {
            right = mid;
        }
    }

    //cout << "left : " << left << endl;

    int tak = data.size()-1 - left;
    int inv = lower_bound(all(data), p - abs(data[left] - p)) - data.begin();
    //if (data[inv] == p - (data[left] - p)) inv--;
    int aok = left - inv + 1;
    //cout << "tak = " << tak << " , aok = " << aok << endl;
    //cout << "inv = " << inv << endl;
    if (tak == aok) {
        return {left+1, inv-1};
    } else {
        return {left+1, inv-2};
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n ,q);
    int as = 0;
    vector<int> data(n), odd(n+1, 0), even(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        as += data[i];
        if (i % 2) {
            odd[i] += data[i];
        } else {
            even[i] += data[i];
        }
        odd[i+1] += odd[i];
        even[i+1] += even[i];
    }

    //rep(i, odd.size()) cout << odd[i] << " "; cout << endl;
    //rep(i, even.size()) cout << even[i] << " "; cout << endl;

    vi revs(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        revs[i] = data[i] + revs[i+1];
    }

    //rep(i, revs.size()) cout << revs[i] << " "; cout << endl;
    
    while (q--) {
        Int(tmp);
        auto ret = solve(data, tmp);
        //cout << ret.fir << " " << ret.sec << endl;
        int ss = revs[ret.fir];
        if (ret.sec >= 0) {
            if (ret.sec % 2) {
                ss += odd[ret.sec];
            } else {
                ss += even[ret.sec];
            }
        }
        //cout << "ss = " << ss << endl;
        cout << ss << endl;
    }


    return 0;
}
