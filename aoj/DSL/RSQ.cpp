template <typename T>
class FenwickTree {
    private:
        vector<T> bit;
        int size;
    public:
        FenwickTree(int _size) : bit(vector<T>(_size+1, 0)), size(_size) {}
        int sum(int i) {
            if (!i) return 0;
            return bit[i] + sum(i - (i & -i));
        }
        void add(int i, T x) {
            if (i > size) return;
            bit[i] += x;
            add(i + (i & -i), x);
        }
};

signed main() {
    int N, Q;
    cin >> N >> Q;
    FenwickTree<int> fenwick(N);
    for (int i = 0; i < Q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            fenwick.add(x, y);
        } else {
            if (x > y) swap(x, y);
            cout << (fenwick.sum(y) - fenwick.sum(x - 1)) << endl;
        }
    }
}
