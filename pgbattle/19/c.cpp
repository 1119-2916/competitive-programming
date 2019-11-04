#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-10
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
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};
template< typename structure_t, typename get_t, typename update_t >
struct SegmentTree2DCompressed {

    using merge_f = function< get_t(get_t, get_t) >;
    using range_get_f = function< get_t(structure_t &, int, int) >;
    using update_f = function< void(structure_t &, int, update_t) >;

    int sz;
    vector< structure_t > seg;
    const merge_f f;
    const range_get_f g;
    const update_f h;
    const get_t identity;
    vector< vector< int > > LL, RR;
    vector< vector< int > > beet;

    SegmentTree2DCompressed(int n, const merge_f &f, const range_get_f &g, const update_f &h, const get_t &identity)
        : f(f), g(g), h(h), identity(identity) {
            sz = 1;
            while(sz < n) sz <<= 1;
            beet.resize(2 * sz);
            LL.resize(2 * sz);
            RR.resize(2 * sz);
        }

    void update(int a, int x, update_t z, int k, int l, int r) {
        if(r <= a || a + 1 <= l) return;
        if(a <= l && r <= a + 1) return h(seg[k], x, z);
        update(a, LL[k][x], z, 2 * k + 0, l, (l + r) >> 1);
        update(a, RR[k][x], z, 2 * k + 1, (l + r) >> 1, r);
        return h(seg[k], x, z);
    }

    void update(int x, int y, update_t z) {
        y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
        return update(x, y, z, 1, 0, sz);
    }

    get_t query(int a, int b, int x, int y, int k, int l, int r) {
        if(a >= r || b <= l) return identity;
        if(a <= l && r <= b) return g(seg[k], x, y);
        return f(query(a, b, LL[k][x], LL[k][y], 2 * k + 0, l, (l + r) >> 1),
                query(a, b, RR[k][x], RR[k][y], 2 * k + 1, (l + r) >> 1, r));
    }

    get_t query(int a, int b, int x, int y) {
        x = lower_bound(begin(beet[1]), end(beet[1]), x) - begin(beet[1]);
        y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
        return query(a, b, x, y, 1, 0, sz);
    }

    void build() {
        for(int k = (int) beet.size() - 1; k >= sz; k--) {
            sort(begin(beet[k]), end(beet[k]));
            beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
        }
        for(int k = sz - 1; k > 0; k--) {
            beet[k].resize(beet[2 * k + 0].size() + beet[2 * k + 1].size());
            merge(begin(beet[2 * k + 0]), end(beet[2 * k + 0]), begin(beet[2 * k + 1]), end(beet[2 * k + 1]), begin(beet[k]));
            beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
            LL[k].resize(beet[k].size() + 1);
            RR[k].resize(beet[k].size() + 1);
            int tail1 = 0, tail2 = 0;
            for(int i = 0; i < beet[k].size(); i++) {
                while(tail1 < beet[2 * k + 0].size() && beet[2 * k + 0][tail1] < beet[k][i]) ++tail1;
                while(tail2 < beet[2 * k + 1].size() && beet[2 * k + 1][tail2] < beet[k][i]) ++tail2;
                LL[k][i] = tail1, RR[k][i] = tail2;
            }
            LL[k][beet[k].size()] = (int) beet[2 * k + 0].size();
            RR[k][beet[k].size()] = (int) beet[2 * k + 1].size();
        }
        for(int k = 0; k < beet.size(); k++) {
            seg.emplace_back(structure_t(beet[k].size()));
        }
    }

    void preupdate(int x, int y) {
        beet[x + sz].push_back(y);
    }
};

namespace fast {
    // fast I/O by rsk0315 (update: 2019-08-08 07:02:47).
    // This version supports only integer inputs/outputs, single character
    // outputs, and string literal outputs.
    static size_t constexpr buf_size = 1 << 17;
    static size_t constexpr margin = 1;
    static char inbuf[buf_size + margin] = {};
    static char outbuf[buf_size + margin] = {};
    static __attribute__((aligned(8))) char minibuf[32];
    static size_t constexpr int_digits = 20;  // 18446744073709551615
    static uintmax_t constexpr digit_mask = 0x3030303030303030;
    static uintmax_t constexpr first_mask = 0x00FF00FF00FF00FF;
    static uintmax_t constexpr second_mask = 0x0000FFFF0000FFFF;
    static uintmax_t constexpr third_mask = 0x00000000FFFFFFFF;
    static uintmax_t constexpr tenpow[] = {
        1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000
    };
    template <typename Tp>
        using enable_if_integral = std::enable_if<std::is_integral<Tp>::value, Tp>;

    class scanner {
        char* pos = inbuf;
        char* endpos = inbuf + buf_size;

        void M_read_from_stdin() {
            endpos = inbuf + fread(pos, 1, buf_size, stdin);
        }
        void M_reread_from_stdin() {
            ptrdiff_t len = endpos - pos;
            if (!(inbuf + len <= pos)) return;
            memcpy(inbuf, pos, len);
            char* tmp = inbuf + len;
            endpos = tmp + fread(tmp, 1, buf_size-len, stdin);
            *endpos = 0;
            pos = inbuf;
        }

        public:
        scanner() { M_read_from_stdin(); }

        template <typename Integral,
                 typename enable_if_integral<Integral>::type* = nullptr>
                     void scan_parallel(Integral& x) {
                         // See https://qiita.com/rsk0315_h4x/items/17a9cb12e0de5fd918f4
                         if (__builtin_expect(endpos <= pos + int_digits, 0))
                             M_reread_from_stdin();
                         bool ends = false;
                         typename std::make_unsigned<Integral>::type y = 0;
                         bool neg = false;
                         if (std::is_signed<Integral>::value && *pos == '-') {
                             neg = true;
                             ++pos;
                         }
                         do {
                             memcpy(minibuf, pos, 8);
                             long c = *(long*)minibuf;
                             long d = (c & digit_mask) ^ digit_mask;
                             int skip = 8;
                             int shift = 8;
                             if (d) {
                                 int ctz = __builtin_ctzl(d);
                                 if (ctz == 4) break;
                                 c &= (1L << (ctz-5)) - 1;
                                 int discarded = (68-ctz) / 8;
                                 shift -= discarded;
                                 c <<= discarded * 8;
                                 skip -= discarded;
                                 ends = true;
                             }
                             c |= digit_mask;
                             c ^= digit_mask;
                             c = ((c >> 8) + c*10) & first_mask;
                             c = ((c >> 16) + c*100) & second_mask;
                             c = ((c >> 32) + c*10000) & third_mask;
                             y = y*tenpow[shift] + c;
                             pos += skip;
                         } while (!ends);
                         x = (neg? -y: y);
                         ++pos;
                     }

        template <typename Integral,
                 typename enable_if_integral<Integral>::type* = nullptr>
                     void scan_serial(Integral& x) {
                         if (__builtin_expect(endpos <= pos + int_digits, 0))
                             M_reread_from_stdin();
                         bool neg = false;
                         if (std::is_signed<Integral>::value && *pos == '-') {
                             neg = true;
                             ++pos;
                         }
                         typename std::make_unsigned<Integral>::type y = *pos-'0';
                         while (*++pos >= '0') y = 10*y + *pos-'0';
                         x = (neg? -y: y);
                         ++pos;
                     }

        template <typename Integral,
                 typename enable_if_integral<Integral>::type* = nullptr>
                     // Use scan_parallel(x) only when x may be too large (about 10^12).
                     // Otherwise, even when x <= 10^9, scan_serial(x) may be faster.
                     void scan(Integral& x) { scan_serial(x); }
    };

    class printer {
        char* pos = outbuf;

        void M_flush_stdout() {
            fwrite(outbuf, 1, pos-outbuf, stdout);
            pos = outbuf;
        }

        public:
        printer() = default;
        ~printer() { M_flush_stdout(); }

        void print(char c) {
            if (__builtin_expect(pos + 1 >= outbuf + buf_size, 0)) M_flush_stdout();
            *pos++ = c;
        }

        template <size_t N>
            void print(char const(&s)[N]) {
                if (__builtin_expect(pos + N >= outbuf + buf_size, 0)) M_flush_stdout();
                memcpy(pos, s, N-1);
                pos += N-1;
            }

        template <typename Integral,
                 typename enable_if_integral<Integral>::type* = nullptr>
                     void print(Integral x) {
                         if (__builtin_expect(pos + int_digits >= outbuf + buf_size, 0))
                             M_flush_stdout();
                         if (x == 0) {
                             *pos++ = '0';
                             return;
                         }
                         if (x < 0) {
                             *pos++ = '-';
                             if (__builtin_expect(x == std::numeric_limits<Integral>::min(), 0)) {
                                 switch (sizeof x) {
                                     case 2: print("32768"); return;
                                     case 4: print("2147483648"); return;
                                     case 8: print("9223372036854775808"); return;
                                 }
                             }
                             x = -x;
                         }
                         char* mp = minibuf + sizeof minibuf;
                         *--mp = x % 10 + '0';
                         size_t len = 1;
                         typename std::make_unsigned<Integral>::type y = x / 10;
                         while (y > 0) {
                             *--mp = y % 10 + '0';
                             y /= 10;
                             ++len;
                         }
                         memcpy(pos, mp, len);
                         pos += len;
                     }

        template <typename Tp>
            void println(Tp x) { print(x), print('\n'); }
    };
} // fast::

fast::scanner in;
fast::printer out;

int x[300000], y[300000], d[300000];

int main()
{
    cout << "ok" << endl;
    using BIT = BinaryIndexedTree< int >;
    auto f = [](int x, int y) { return x + y; };
    auto g = [](BIT &k, int x, int y) { return k.sum(y - 1) - k.sum(x - 1); };
    auto h = [](BIT &k, int x, int y) { k.add(x, y); };

    cout << "ok" << endl;

    int n; 
    in.scan(n);
    out.println(n);

    SegmentTree2DCompressed< BIT, int, int > seg(12010, f, g, h, 0);

    rep(i, n) {
        in.scan(x[i]);
        in.scan(y[i]);
        in.scan(d[i]);
        seg.update(x[i] + y[i], x[i] - y[i], 1);
    }

    //cout << "ok" << endl;

    rep(i, n) {
        out.println(seg.query(x[i] - d[i] + y[i], x[i] - d[i] - y[i], x[i] + d[i] + y[i], x[i] + d[i] - y[i]));
    }

    return 0;
}
