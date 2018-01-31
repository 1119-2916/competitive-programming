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
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin


struct segtree {
    int H, W;
    vector<vector<int>> dat;
    segtree(){}
    // vviを作ってからコンストラクタを呼ぶ
    segtree(vector<vector<int>> &f) {
        H = W = 1;
        while(H < (int)f.size()) H <<= 1;
        while(W < (int)f[0].size()) W <<= 1;
        dat.assign(2*H-1,vector<int>(2*W-1,0));
        init(f);
    }
    void init(vector<vector<int>> &f) {
        for (int i = 0; i < (int)f.size(); i++)
            for (int j = 0; j < (int)f[0].size(); j++)
                dat[i+H-1][j+W-1] = f[i][j];
        for (int i = 2*H-2; i > H-2; i--)
            for (int j = W-2; j >= 0; j--)
                dat[i][j] = dat[i][2*j+1]+dat[i][2*j+2];
        for (int i = H-2; i >= 0; i--)
            for (int j = 0; j < 2*W-1; j++)
                dat[i][j] = dat[2*i+1][j]+dat[2*i+2][j];
    }
    // 当然半開区間
    int minimum(int li, int lj, int ri, int rj) { return minimum_h(li,lj,ri,rj,0,H,0); }
    int minimum_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
        if(ri <= si or ti <= li) return 0;
        if(li <= si and ti <= ri) return minimum_w(lj,rj,0,W,k,0);
        const int mi = (si+ti)/2;
        return minimum_h(li,lj,ri,rj,si,mi,2*k+1) + minimum_h(li,lj,ri,rj,mi,ti,2*k+2);
    }
    int minimum_w(int lj, int rj, int sj, int tj, int i, int k) {
        if(rj <= sj or tj <= lj) return 0;
        if(lj <= sj and tj <= rj) return dat[i][k];
        const int mj = (sj+tj)/2;
        return minimum_w(lj,rj,sj,mj,i,2*k+1)+minimum_w(lj,rj,mj,tj,i,2*k+2);
    }
};


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int2(n, k);

    vvi w1(k, vi(k, 0)), b1(k, vi(k, 0));
    vvi w2(k, vi(k, 0)), b2(k, vi(k, 0));

    rep(i, n) {
        int2(a, b);
        char c; cin >> c;
        if ((a/k+b/k)%2) {
            if (c == 'W') {
                w1[a%k][b%k]++;
            } else {
                b1[a%k][b%k]++;
            }
        } else {
            if (c == 'W') {
                w2[a%k][b%k]++;
            } else {
                b2[a%k][b%k]++;
            }
        }
    }
    segtree sw1(w1), sw2(w2), sb1(b1), sb2(b2);
    sw1.init(w1), sw2.init(w2), sb1.init(b1), sb2.init(b2);

    int ans = 0;
    rep(i, k) {
        rep(j, k) {
            ans = max(ans, 
                    sw1.minimum(i, j, k, k) + sw1.minimum(0, 0, i, j) +
                    sw2.minimum(i, 0, k, j) + sw2.minimum(0, j, i, k) +
                    sb2.minimum(i, j, k, k) + sb2.minimum(0, 0, i, j) +
                    sb1.minimum(i, 0, k, j) + sb1.minimum(0, j, i, k));
/*
            cout << 
                sw1.minimum(i, j, k, k) <<
                sw1.minimum(0, 0, i+1, j+1) << 
                sb1.minimum(i, 0, k, j+1) << 
                sb1.minimum(0, j, i+1, k) <<
                sw2.minimum(i, 0, k, j+1) << 
                sw2.minimum(0, j, i+1, k) << 
                sb2.minimum(0, 0, i+1, j+1) << 
                sb2.minimum(i, j, k, k) << 
                endl;*/
        }
    }
    cout << ans << endl;
    return 0;
}
