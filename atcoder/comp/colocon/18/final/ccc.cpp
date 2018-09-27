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
// BIT CHT DiscreteFourierTransform FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

int cnt = 0;

/**
 * 動的 CHT 単調性無しok 各操作 O(logN)
 * **必ず厳密な探索範囲[minn, maxx]を与えること**
 * T = int 以外で未検証
 * 得られるのは最大値
 */
template <typename T, const T id = numeric_limits<T>::min()>
class CHT {
    using L = T;   // 返り値の型 (縦軸)
    const T accuracy = 0;  // 精度 (横軸)
    struct Line {
        T a, b;
        Line (T a = 0, T b = 0) : a(a), b(b) {}
        L get (T x) { return a * x + b; }
    };
    struct Node {
        Line line;
        Node *lch, *rch;
        Node (Line line) : line(line), lch(nullptr), rch(nullptr) {}
    };

    private :
    // 探索区間（横軸）の最小、最大
    const T minn, maxx; 
    Node *root;

    // [lb, ub]
    Node* update(Node *p, T lb, T ub, Line& line) {
        //cout << "call update : " << line.a << " " << line.b << endl;
        cnt++;
        if (!p) return new Node(line);
        //cout << "p->line.get(lb) : " << p->line.get(lb) << "   line.get(lb) : " << line.get(lb) << endl;
        //cout << "p->line.get(ub) : " << p->line.get(ub) << "   line.get(ub) : " << line.get(ub) << endl;
        if (p->line.get(lb) >= line.get(lb) && 
                p->line.get(ub) >= line.get(ub)) return p;
        if (p->line.get(lb) <= line.get(lb) && 
                p->line.get(ub) <= line.get(ub)) {
            p->line = line;
            return p;
        }
        T mid = (lb + ub) / 2;
        if (p->line.get(mid) < line.get(mid)) swap(p->line, line);
        if (p->line.get(lb) <= line.get(lb))
            p->lch = update(p->lch, lb, mid, line);
        else 
            p->rch = update(p->rch, mid, ub, line);
        return p;
    }
    L query(Node *p, T lb, T ub, T t) {
        if (!p) { return id; }
        if (ub - lb <= accuracy) return p->line.get(t);
        T mid = (lb + ub) / 2;
        if (t <= mid) {
            return max(p->line.get(t), query(p->lch, lb, mid, t));
        }
        return max(p->line.get(t), query(p->rch, mid, ub, t));
    }

    public :
    CHT (const T minn, const T maxx) : minn(minn), maxx(maxx), root(nullptr) {}
    void insert(T a, T b) {
        cnt = 0;
        Line line(a, b);
        root = update(root, minn, maxx, line);
        //cout << " 木の高さ : " << cnt << endl;
        cnt = 0;
    }
    L get(T x) {
        return query(root, minn, maxx, x);
    }

};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n);
    int yui = INF, kyoko = 0;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        yui = min(yui, data[i]);
        kyoko = max(kyoko, data[i]);
    }
    
    //CHT<int> funami(yui, kyoko);
    CHT<int> funami(0, 1100010001000);
    rep(i, n) {
        funami.insert(2 * i, -(data[i] + i * i));
        //funami.insert(2 * i, i);
    }

    rep(i, n) {
        cout << - funami.get(i) + i * i << endl;
    }


    return 0;
}
