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
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

template <class T>
struct avl_tree {
    struct node {
        T key;
        int size, height;
        node *child[2];
        node(const T &key) : key(key), size(1), height(1) {
            child[0] = child[1] = 0; }
    } *root;
    typedef node *pointer;
    avl_tree() { root = NULL; }

    // keyと一致する要素が発見されればその参照を、
    // されなければNullを返す
    pointer find(const T &key) { return find(root, key); }
    node *find(node *t, const T &key) {
        if (t == NULL) return NULL;
        if (key == t->key) return t;
        else if (key < t->key) return find(t->child[0], key);
        else                   return find(t->child[1], key);
    }
    // 要素の挿入
    void insert(const T &key) { root = insert(root, new node(key)); }
    node *insert(node *t, node *x) {
        if (t == NULL) return x;
        if (x->key <= t->key) t->child[0] = insert(t->child[0], x);
        else                  t->child[1] = insert(t->child[1], x);
        t->size += 1;
        return balance(t);
    }
    // 要素の削除
    void erase(const T &key) { root = erase(root, key); }
    node *erase(node *t, const T &x) {
        if (t == NULL) return NULL;
        if (x == t->key) {
            return move_down(t->child[0], t->child[1]);
        } else {
            if (x < t->key) t->child[0] = erase(t->child[0], x);
            else            t->child[1] = erase(t->child[1], x);
            t->size -= 1;
            return balance(t);
        }
    }
    node *move_down(node *t, node *rhs) {
        if (t == NULL) return rhs;
        t->child[1] = move_down(t->child[1], rhs);
        return balance(t);
    }
#define sz(t) (t ? t->size : 0)
#define ht(t) (t ? t->height : 0)
    node *rotate(node *t, int l, int r) {
        node *s = t->child[r];
        t->child[r] = s->child[l];
        s->child[l] = balance(t);
        if (t) t->size = sz(t->child[0]) + sz(t->child[1]) + 1;
        if (s) s->size = sz(s->child[0]) + sz(s->child[1]) + 1;
        return balance(s);
    }
    node *balance(node *t) {
        for (int i = 0; i < 2; ++i) {
            if (ht(t->child[!i]) - ht(t->child[i]) < -1) {
                if (ht(t->child[i]->child[!i]) - ht(t->child[i]->child[i]) > 0)
                    t->child[i] = rotate(t->child[i], i, !i);
                return rotate(t, !i, i);
            }
        }
        if (t) t->height = max(ht(t->child[0]), ht(t->child[1])) + 1;
        if (t) t->size = sz(t->child[0]) + sz(t->child[1]) + 1;
        return t;
    }
    // 小さい順にk番目の要素がどんなkeyを持つのかを調べる
    /*
     * 要素数を保持しておいて、木内でi番目の要素が
     * 何なのかが分かるのを利用して二分探索をするとか。
     int a = 目的の値
     int st = -1, ed = tree.size(), mid;        //xxxooo, (st, ed]
     while (ed - st >= 2) {
     mid = (st + ed) / 2;
     if ((tree.rank(mid))->key >= a) ed = mid;
     else st = mid;
     }
     cout << sz - ed << endl;
     */
    pointer rank(int k) const { return rank(root, k); }
    pointer rank(node *t, int k) const {
        if (!t) return NULL;
        int m = sz(t->child[0]);
        if (k  < m) return rank(t->child[0], k);
        if (k == m) return t;
        if (k  > m) return rank(t->child[1], k - m - 1);
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(q);
    avl_tree<int> mm;

    int c = 0, sum = 0, left = 0, right = 0, mid = INF;
    int lc = 0, rc = 0;
    rep(i, q) {
        Int(tmp);
        if (tmp == 1) {
            int2(a, b);
            c += b;
            mm.insert(a);
            sum++;
            if (a < mid) {
                left += a;
                lc++;
            } else {
                right += a;
                rc++;
            }
            if (mid == INF) {
                mid = a;
                left = 0; right = 0;
                lc = 0; rc = 0;
            } else {
                int nmid = mm.rank(sum/2l)->key;
                if (nmid < mid) { // 小さい方に挿入
                    right += mid;
                    //left -= nmid;
                    rc++; lc--;
                } else {
                    left += mid;
                    //right -= nmid;
                    lc++; rc--;
                }
            }
            cout << "c :" << c << ", sum = " << sum <<
                ", left = " << left << ", right = " <<
                right << ", mid = " << mid << endl;
        } else {
            if (mid == INF) {
                cout << "0 0" << endl;
            } else {
                cout << mid << " ";
                cout << c + (lc * mid) - left + right - (rc * mid) << endl;
            }
        }
    }


    return 0;
}
