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


template <typename T, const T id>
class CHT {
    struct Line {
        T a, b;
        Line (T a = 0, T b = 0) : a(a), b(b) {}
        T get (T x) { return a * x + b; }
    };
    struct Node {
        Line line;
        Node *lch, *rch;
        Node (Line line) : line(line), lch(nullptr), rch(nullptr) {}
    };

private :
    const int n;
    const vector<T> pos;
    Node *root;

public :
    CHT (const vector<T>& pos) : n(pos.size()), pos(pos), root(nullptr) {}
    void insert(T a, T b) {
        Line line(a, b);
        root = modify(root, 0, n, line);
    }
    T query(T x) {
        int t = lower_bound(pos.begin(), pos.end(), x) - pos.begin();
        assert(t < n && pos[t] == x);
        return sub(root, 0, n, t);
    }

private :
    Node* modify(Node *p, int lb, int ub, Line& line) {
        if (!p) return new Node(line);
        if (p->line.get(pos[lb]) >= line.get(pos[lb]) && 
                p->line.get(pos[ub-1]) >= line.get(pos[ub-1])) return p;
        if (p->line.get(pos[lb]) <= line.get(pos[lb]) && 
                p->line.get(pos[ub-1]) <= line.get(pos[ub-1])) {
            p->line = line;
            return p;
        }
        int mid = (lb + ub) / 2;
        if (p->line.get(pos[mid]) < line.get(pos[mid])) swap(p->line, line);
        if (p->line.get(pos[lb]) <= line.get(pos[lb]))
            p->lch = modify(p->lch, lb, mid, line);
        else 
            p->rch = modify(p->rch, mid, ub, line);
        return p;
    }
    T sub(Node *p, int lb, int ub, int t) {
        if (!p) {
            return id;
        }
        if (ub - lb == 1) return p->line.get(pos[t]);
        int mid = (lb + ub) / 2;
        if (t < mid) {
            return max(p->line.get(pos[t]), sub(p->lch, lb, mid, t));
        }
        return max(p->line.get(pos[t]), sub(p->rch, mid, ub, t));
    }
};


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, k);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    vi arr = data;
    sort(all(arr)); arr.erase(unique(all(arr)), arr.end());

    vvi dp(k+1, vi(n+1, INF));
    dp[0][0] = 0;
    rep(i, k) {
        CHT<int, -INF> funami(arr);
        rep(a, n) {
            funami.insert(2 * data[a], -(dp[i][a] + data[a] * data[a]));
            dp[i+1][a+1] = data[a] * data[a] - funami.query(data[a]);
        }
    }
    cout << dp[k][n] << endl;

    return 0;
}
