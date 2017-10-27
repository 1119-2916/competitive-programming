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
    pointer rank(int k) const { return rank(root, k); }
    pointer rank(node *t, int k) const {
        if (!t) return NULL;
        int m = sz(t->child[0]);
        if (k  < m) return rank(t->child[0], k);
        if (k == m) return t;
        if (k  > m) return rank(t->child[1], k - m - 1);
    }
};

int maxs[100000];
avl_tree<int> beet;

int n, q;
int type, a, b;
int sz = 0;

int main()
{
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> a >> b;
            b--;
            if (maxs[b] != 0) beet.erase(maxs[b]);
            if (maxs[b] == 0) sz++;
            maxs[b] = max(maxs[b], a);
            beet.insert(maxs[b]);
        }
        else {
            cin >> a;
            //安定のライブラリ、平衡2分木＋2分探索
            int st = -1, ed = sz, mid;        //xxxooo, (st, ed]
            while (ed - st >= 2) {
                mid = (st + ed) / 2;
                if ((beet.rank(mid))->key >= a) ed = mid;
                else st = mid;
            }
            cout << sz - ed << endl;
        }
    }

    return 0;
}
