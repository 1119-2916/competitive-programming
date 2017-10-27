
template< class T >
struct BinaryIndexedTree
{
    vector< T > data;

    BinaryIndexedTree(int sz)
    {
        data.assign(++sz, 0);
    }

    T sum(int k)
    {
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    void add(int k, T x)
    {
        for(++k; k < data.size(); k += k & -k) data[k] += x;
    }
};


vector<int> bit(n);

int n;

int sum(int i)
{
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x)
{
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}
