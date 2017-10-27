using namespace std;

class segtree
{
    private:
        int dfs(int a,int b,int k,int l,int r)
        {
            //* 要求範囲を含まないレンジの探索.
            if (r <= a || b <= l) {
                return INF;
            }
            //* 木のレンジが要求範囲以下になる時.
            if (a <= l && r <= b) {
                return tree[k];
            }
            int m = (l+r)/2;
            return min(dfs(a, b, k*2+1, l, m), dfs(a, b, k*2+2, m, r));
        }
    public:
        int size = 262144;
        int tree[size];

        segtree(int c) {
            for (int i = 0; i < size; i++) {
                tree[i] = c;
            }
        }

        int getMin(int right, int left)
        {
            return dfs(right, left, 0, 0, RMQ_SIZE/2);
        }

        void update(int pos, int value)
        {
            pos += (RMQ_SIZE/2 -1);
            tree[pos] = value;
            while (pos) {
                pos = (pos-1)/2;
                tree[pos] = min(tree[pos*2+1], tree[pos*2+2]);
            }
        }
}
