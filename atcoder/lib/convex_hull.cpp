#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

/*
 * 単調追加、任意クエリ
 * c++14
 */
template<typename T>
class ConvecHullTrick {
    private:
        // 直線群(配列)
        std::vector< std::pair<T, T> > lines;
        // 最小値(最大値)を求めるxが単調であるか
        bool isMonotonicX;
        // 最小/最大を判断する関数
        std::function<bool(T l, T r)> comp;

    public:
        // コンストラクタ ( クエリが単調であった場合はflag = trueとする )
        ConvecHullTrick(bool flagX = false, std::function<bool(T l, T r)> compFunc = [](T l, T r) {return l >= r; })
            :isMonotonicX(flagX), comp(compFunc)  {
                lines.emplace_back(0, 0);
            };

        // 直線l1, l2, l3のうちl2が不必要であるかどうか
        bool check(std::pair<T, T> l1, std::pair<T, T> l2, std::pair<T, T> l3) {
            if (l1 < l3) std::swap(l1, l3);
            return (l3.second - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) * (l3.first - l2.first);
        }

        // 直線y=ax+bを追加する
        void add(T a, T b) {
            std::pair<T, T> line(a, b);
            while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line))
                lines.pop_back();
            lines.emplace_back(line);
        }

        // i番目の直線f_i(x)に対するxの時の値を返す
        T f(int i, T x) {
            return lines[i].first * x + lines[i].second;
        }

        // i番目の直線f_i(x)に対するxの時の値を返す
        T f(std::pair<T, T> line, T x) {
            return line.first * x + line.second;
        }

        // 直線群の中でxの時に最小(最大)となる値を返す
        T get(T x) {
            // 最小値(最大値)クエリにおけるxが単調
            if (isMonotonicX) {
                static int head = 0;
                while (lines.size() - head >= 2 && comp(f(head, x), f(head + 1, x)))
                    ++head;
                return f(head, x);
            }
            else {
                int low = -1, high = lines.size() - 1;
                while (high - low > 1) {
                    int mid = (high + low) / 2;
                    (comp(f(mid, x), f(mid + 1, x)) ? low : high) = mid;
                }
                return f(high, x);
            }
        }
};


/*
 * 単調追加、任意クエリ
 * c++14
 */
// Treap
// 分割した木に対して操作する必要があるなら Node* を返す
// 乱数は rand() で十分なはず
// 遅延評価版も作る
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2299004#1
// http://arc033.contest.atcoder.jp/submissions/1261629
struct Treap {
    using Val = int;
    struct Node {
        Val val, sum, mini;
        Node *left, *right;
        int pri;
        int size;
        Node(Val v, int p)
            :val(v), mini(v), pri(p), size(1), sum(v) {
                left = right = NULL;
            }
    };
    int size(Node *t) { return !t ? 0 : t->size; }
    Val sum(Node *t) { return !t ? 0 : t->sum; }
    Val val(Node *t) { assert(t); return t->val; }
    Val mini(Node *t) { return !t ? INF : t->mini; }

    Node* root;
    Treap() :root(NULL) {};

    // 子が変わったときに必ず呼ぶ
    Node *update(Node *t) {
        if (!t)return t;
        t->size = size(t->left) + size(t->right) + 1;
        t->sum = sum(t->left) + sum(t->right) + t->val;
        t->mini = min({ val(t),mini(t->left),mini(t->right) });
        return t;
    }

    Node *update(Node *t, int k, Val v) {
        return insertAt(eraseAt(t, k), k, v);
    }

    Val mini(Node *t, int l, int r) {
        if (!t)return INF;
        if (r <= l)return INF;
        if (r - l == size(t))
            return mini(t);
        else if (size(t->left) >= r)
            return mini(t->left, l, r);
        else if (size(t->left) < l)
            return mini(t->right, l - (size(t->left) + 1), r - (size(t->left) + 1));
        return min({
                val(t),
                mini(t->left, l, size(t->left)),
                mini(t->right, 0, r - (size(t->left) + 1))
                });
    }

    Node *merge(Node *l, Node *r) {
        if (!l)return r;
        if (!r)return l;
        if (l->pri > r->pri) {
            l->right = merge(l->right, r);
            return update(l);
        }
        else {
            r->left = merge(l, r->left);
            return update(r);
        }
    }

    // ([0, k), [k, n))
    pair<Node*, Node*> split(Node *t, int k) {
        if (!t)return pair<Node*, Node*>(NULL, NULL);
        if (k <= size(t->left)) {
            pair<Node*, Node*> s = split(t->left, k);
            t->left = s.second;
            return make_pair(s.first, update(t));
        }
        else {
            pair<Node*, Node*> s = split(t->right, k - size(t->left) - 1);
            t->right = s.first;
            return make_pair(update(t), s.second);
        }
    }

    int lowerbound(Node *t, Val v) {
        if (!t) return 0;
        if (v <= val(t))
            return lowerbound(t->left, v);
        else
            return size(t->left) + 1 + lowerbound(t->right, v);
    }

    Node *insertAt(Node *t, int k, Val v) {
        auto s = split(t, k);
        Node *m = new Node(v, rand());
        return update(merge(update(merge(s.first, m)), s.second));
    }

    Node *insert(Node *t, Val v) {
        return insertAt(t, lowerbound(t, v), v);
    }

    Node *eraseAt(Node *t, int k) {
        auto s1 = split(t, k);
        auto s2 = split(s1.second, 1);
        return update(merge(s1.first, s2.second));
    }

    Node *at(Node *t, int k) {
        assert(size(t) > k);
        auto s = split(t, k);
        Node *ret = s.second;
        while (ret->left)
            ret = ret->left;
        merge(s.first, s.second);
        return ret;
    }

    Node* circularShift(Node *t, int l, int r) {
        Node *a, *b, *c, *d;
        tie(a, d) = split(t, r);
        tie(a, b) = split(a, l);
        tie(b, c) = split(b, r - l - 1);
        return merge(merge(a, merge(c, b)), d);
    }
};

ostream &operator<<(ostream &o, Treap t) {
    function<void(Treap::Node*)> rec = [&](Treap::Node *x) {
        if (!x)return;
        rec(x->left);
        cerr << x->val << " ";
        rec(x->right);
    };
    rec(t.root);
}

template<typename T>
class ConvecHullTrick {
    private:
        // 直線群(配列)
        Treap< std::pair<T, T> > lines;
        // 最小値(最大値)を求めるxが単調であるか
        bool isMonotonicX;
        // 最小/最大を判断する関数
        std::function<bool(T l, T r)> comp;

    public:
        // コンストラクタ ( クエリが単調であった場合はflag = trueとする )
        ConvecHullTrick(bool flagX = false, std::function<bool(T l, T r)> compFunc = [](T l, T r) {return l >= r; })
            :isMonotonicX(flagX), comp(compFunc)  {
                lines.insert(make_pair(0, 0));
            };

        // 直線l1, l2, l3のうちl2が不必要であるかどうか
        bool check(std::pair<T, T> l1, std::pair<T, T> l2, std::pair<T, T> l3) {
            if (l1 < l3) std::swap(l1, l3);
            return (l3.second - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) * (l3.first - l2.first);
        }

        // 直線y=ax+bを追加する
        void add(T a, T b) {
            std::pair<T, T> line(a, b);
            while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line))
                lines.pop_back();
            lines.emplace_back(line);
        }

        // i番目の直線f_i(x)に対するxの時の値を返す
        T f(int i, T x) {
            return lines[i].first * x + lines[i].second;
        }

        // i番目の直線f_i(x)に対するxの時の値を返す
        T f(std::pair<T, T> line, T x) {
            return line.first * x + line.second;
        }

        // 直線群の中でxの時に最小(最大)となる値を返す
        T get(T x) {
            // 最小値(最大値)クエリにおけるxが単調
            if (isMonotonicX) {
                static int head = 0;
                while (lines.size() - head >= 2 && comp(f(head, x), f(head + 1, x)))
                    ++head;
                return f(head, x);
            }
            else {
                int low = -1, high = lines.size() - 1;
                while (high - low > 1) {
                    int mid = (high + low) / 2;
                    (comp(f(mid, x), f(mid + 1, x)) ? low : high) = mid;
                }
                return f(high, x);
            }
        }
};
