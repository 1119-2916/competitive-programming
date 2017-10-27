#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2147483647
#define RMQ_SIZE 262144

using namespace std;

class segtree
{
    private:
        int dfs(int a,int b,int k,int l,int r)
        {
            //* 要求範囲を含まないレンジの探索.
            if (r <= a || b <= l) {
                return 0;
            }
            //* 木のレンジが要求範囲以下になる時.
            if (a <= l && r <= b) {
                return tree[k];
            }
            int m = (l+r)/2;
            return dfs(a, b, k*2+1, l, m) + dfs(a, b, k*2+2, m, r);
        }
    public:
        int size;
        vi tree;

        segtree(int _size, int _firstnum){
            size = 1;
            while (size < _size) size *= 2;
            size <<= 1;
            tree = vi(size, 0);
            if (_firstnum) {
                rep(i, tree.size()) tree[i] = _firstnum;
            }
        }
        segtree(int _size){
            size = 1;
            while (size < _size) size *= 2;
            size <<= 1;
            tree = vi(size, 0);
        }
        int get_sum(int left, int right)
        {
            return dfs(left, right, 0, 0, size/2);
        }
        void update(int pos, int value)
        {
            pos += (size/2 -1);
            tree[pos] = value;
            while (pos) {
                pos = (pos-1)/2;
                tree[pos] = tree[pos*2+1] + tree[pos*2+2];
            }
        }
        int get_allsum()
        {
            return tree[0];
        }
};

int main()
{
    int n, q;
    cin >> n >> q;
    segtree st(n);

    for (int i = 0; i < q; i++) {
        int tmp, a, b;
        cin >> tmp >> a >> b;
        if (tmp) {
            cout << st.get_sum(a, b+1) << endl;
        } else {
            st.update(a, b);
        }
    }
            
    return 0;
}
