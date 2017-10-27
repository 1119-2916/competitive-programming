#include <iostream>
#include <algorithm>

#define INF 2147483647
#define RMQ_SIZE 262144

using namespace std;

void update(int pos, int value);
int getMin(int right, int left);
int dfs(int a,int b,int k,int l,int r);

int tree[RMQ_SIZE];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i <= n; i++) {
        update(i, INF);
    }
    for (int i = 0; i < q; i++) {
        int tmp, a, b;
        cin >> tmp >> a >> b;
        if (tmp) {
            cout << getMin(a, b+1) << endl;
        } else {
            update(a, b);
        }
    }
            
    return 0;
}


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

