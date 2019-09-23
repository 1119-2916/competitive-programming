    LazySegTree<ll, LAZ> S(N,
    [](ll a, ll b){return min(a,b);}),
    [](ll a, LAZ b, int len){return (ll)(b.first*a)+b.second; },
    [](LAZ a, LAZ b){return LAZ(a.first*b.first, (ll)(b.first*a.second)+b.second);},
    (ll)1e63);

    using box = vector<ll>;
template <typename T, typename U>
struct LazySegTree
{
    int n;
    function<T(T, T)> calc;
    function<T(T, U, int)> apply;
    function<U(U, U)> merge;
    T ex;
    vector<T> data;
    vector<U> lazy;
    vector<bool> is_lazy;
    LazySegTree(int n_, function<T(T, T)>calc,
            function<T(T, U, int)> apply,
            function<U(U, U)> merge,
            T ex)
    {
        this->calc = calc;
        this->apply = apply;
        this->merge = merge;
        this->ex = ex;
        init(n_);
    }
    void init(int n_)
    {
        n = 1;
        while (n < n_) {
            n *= 2;
        }
        data.clear();
        data.resize(2 * n - 1, ex);
        lazy.clear();
        lazy.resize(2 * n - 1, U());
        is_lazy.clear();
        is_lazy.resize(2 * n - 1, false);
    }
    void assign_lazy(int k, U x)
    {
        if (k >= (int)lazy.size()) return ;
        if (is_lazy[k]) {
            lazy[k] = merge(lazy[k], x);
        } else {
            is_lazy[k] = true;
            lazy[k] = x;
        }
    }
    void eval(int len, int k)
    {
        if (!is_lazy[k]) return;
        assign_lazy(k * 2 + 1, lazy[k]);
        assign_lazy(k * 2 + 2, lazy[k]);
        data[k] = apply(data[k], lazy[k], len);
        is_lazy[k] = false;
    }
    T update(int a, int b, U x, int k, int l, int r)
    {
        eval(r - l, k);
        if (r <= a || b <= l) return data[k];
        if (a <= l && r <= b) {
            assign_lazy(k, x);
            return apply(data[k], lazy[k], r - l);
        }
        return data[k] = calc(update(a, b, x, k * 2 + 1, l, (l + r) / 2), 
                update(a, b, x, k * 2 + 2, (l + r) / 2), r);
    }
    T update(int a, int b, U x)
    {
        b++;
        return update(a, b, x, 0, 0, n);
    }
    T query(int a, int b, int k, int l, int r)
    {
        eval(r - l, k);
        if (r <= a || b <= l) return ex;
        if (a <= l && r <= b) return data[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return calc(vl, vr);
    }
    T query(int a, int b)
    {
        b++;
        return query(a, b, 0, 0, n);
    }
};

