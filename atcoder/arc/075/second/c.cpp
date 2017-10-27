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
#define begin(a) a.begin()
#define end(a) a.end()

//int dxy[5] = {0, 1, 0, -1, 0};
// assign

template< class T >
struct BinaryIndexedTree
{
    vector< T > data;

    BinaryIndexedTree(int sz)
    {
        data.assign(++sz, 0);
    }

    T sum(int k)
    {
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    void add(int k, T x)
    {
        for(++k; k < data.size(); k += k & -k) data[k] += x;
    }
};

signed main()
{
    int N, K, A[200000];

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> A[i];

    int sum = 0;
    vector< int > odd;
    odd.push_back(0);
    for(int i = 0; i < N; i++) {
        sum += A[i];
        odd.push_back(sum - (i + 1) * K);
    }
    sort(begin(odd), end(odd));
    odd.erase(unique(begin(odd), end(odd)), end(odd));

    cout << "odd : ";
    rep(i, odd.size()) cout << odd[i] << " ";
    cout << endl;

    sum = 0;
    int ret = 0;
    BinaryIndexedTree< long long > bit(odd.size() + 2);

    cout << lower_bound(begin(odd), end(odd), 0) - begin(odd) << endl;

    bit.add(lower_bound(begin(odd), end(odd), 0) - begin(odd), 1);
    for(int i = 0; i < N; i++) {
        sum += A[i];

        cout << lower_bound(begin(odd), end(odd), sum - (i + 1) * K)
- begin(odd) << " ";
        cout << bit.sum(lower_bound(begin(odd), end(odd), sum - (i + 1) * K)
                - begin(odd)) << endl;

        ret += bit.sum(lower_bound(begin(odd), end(odd), sum - (i + 1) * K)
                - begin(odd));
        bit.add(lower_bound(begin(odd), end(odd), sum - (i + 1) * K) - begin(odd), 1);
    }
    cout << ret << endl;
}

