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
// BIT avl cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 

namespace FFT {
    const double pi = M_PI;
    std::vector<std::complex<double>> tmp;
    size_t sz = 1;
 
    std::vector<std::complex<double>> fft(std::vector<std::complex<double>> a, bool inv = false) {
        size_t mask = sz - 1;
        size_t p = 0;
        for (size_t i = sz >> 1; i >= 1; i >>= 1) {
            auto& cur = (p & 1) ? tmp : a;
            auto& nex = (p & 1) ? a : tmp;
            std::complex<double> e = std::polar(1., 2 * pi * i * (inv ? -1 : 1) / sz);
            std::complex<double> w = 1;
            for (size_t j = 0; j < sz; j += i) {
                for (size_t k = 0; k < i; ++k) {
                    nex[j + k] = cur[((j << 1) & mask) + k] + w * cur[(((j << 1) + i) & mask) + k];
                }
                w *= e;
            }
            ++p;
        }
        if (p & 1) std::swap(a, tmp);
        if (inv) for (size_t i = 0; i < sz; ++i) a[i] /= sz;
        return a;
    }
    std::vector<int> mul(std::vector<int> a, std::vector<int> b) {
        size_t m = a.size() + b.size() - 1;
        sz = 1;
        while (m > sz) sz <<= 1;
        tmp.resize(sz);
        std::vector<std::complex<double>> A(sz), B(sz);
        for (size_t i = 0; i < a.size(); ++i) A[i].real(a[i]);
        for (size_t i = 0; i < b.size(); ++i) B[i].real(b[i]);
        A = fft(A);
        B = fft(B);
        for (size_t i = 0; i < sz; ++i) A[i] *= B[i];
        A = fft(A, true);
        a.resize(m);
        for (size_t i = 0; i < m; ++i) a[i] = std::round(A[i].real());
        return a;
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    Int(n);
    vi a(n+1), b(n+1);
    Rep(i, n+1) {
        cin >> a[i] >> b[i];
    }
    vector<int> ans = FFT::mul(a, b);
    for (int i = 1; i <= 2 * n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
