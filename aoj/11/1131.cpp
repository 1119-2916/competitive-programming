#include <bits/stdc++.h>

using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)

//int dxy[5] = {0, 1, 0, -1, 0};
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
//最小公倍数
int lcm(int x, int y) { return x / gcd(x, y) * y; }

int ans[1000];
int ptr, a;

int solve(int p, int q, int denom, int max_denom, int n)
{
    if (!p || !n) return 0;
    int ret = 0;
    for (int i = max_denom; i * denom <= a; i++) {
        if (p * i < q) continue;
        int tmp = lcm(i, q);
        int s = p * (tmp/q) - tmp / i;
        ret += !s;
        ret += solve(s, tmp, denom * i, i, n-1);
    }
    return ret;
}

signed main()
{
    int p, q, n;
    while (1) {
        scanf("%d %d %d %d", &p, &q, &a, &n);
        if (!q) break;
        ans[ptr++] = solve(p, q, 1, 1, n);
    }

    for (int i = 0; i < ptr; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
