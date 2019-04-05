/*ABCDEFGHIJKLMNOPQRSTUVWX_Z // Y
ABCDEFGHIJKLMN_PQRST_VWXYZ // OU
_BCDEFGHIJKLMNOPQ_STUVWXYZ // AR
ABCD_FGHIJKLMNOPQRSTUVWXYZ // E
_
ABCDEF_H_JKLMNOPQRSTU_WXYZ // GIV
ABCD_FGHIJKLM_OPQRSTUVWXYZ // EN
_
ABCDEFGHIJKLMNOPQRS_UV_XYZ // TW
ABCDEFGHIJKLMN_PQRSTUVWXYZ // O
_
ABCDEFGH_JKLM_OPQRS_UVWXYZ // INT
ABCD_F_HIJKLMNOPQRSTUVWXYZ // EG
ABCD_FGHIJKLMNOPQ__TUVWXYZ // ERS
_
ABCDEFGHIJKLM_OPQRSTUVWXYZ // N
_BCDEFGHIJKLM_OPQRSTUVWXYZ // AN
ABC_EFGHIJKLMNOPQRSTUVWXYZ // D
_
ABCDEFGHIJKL_NOPQRSTUVWXYZ // M
.
_
ABCDEFGHIJKLMNOPQRSTUVWX_Z // Y
ABCDEFGHIJKLMN_PQRST_VWXYZ // OU
ABCDEFGHIJKLMNOPQ_STUVWXYZ // R
_
ABCDEFGHIJKLMNOPQRSUVWXYZ // T
BCDEFGHIJKLMNOPQRTUVWXYZ  // AS
ABCDEFGHIJLMNOPQRSTUVWXYZ // K
_ 
ABCDEFGH_JKLMNOPQR_TUVWXYZ // IS
_
ABCDEFGHIJKLMNOPQRS_UVWXYZ // T
ABCDEFGHIJKLMN_PQRSTUVWXYZ // O
_
ABCDE_GH_JKLM_OPQRSTUVWXYZ // FIN
ABC_EFGHIJKLMNOPQRSTUVWXYZ // D
_
ABCDEFGHIJKLMNOPQRS_UVWXYZ // T
ABCDEFG_IJKLMNOPQRSTUVWXYZ // H
ABCD_FGHIJKLMNOPQRSTUVWXYZ // E
_
ABCDE_GHIJKLMNOPQRSTUVWXYZ // F
_B_DEFGHIJKLMNOPQRS_UVWXYZ // ACT
ABCDEFGHIJKLMN_PQ_STUVWXYZ // OR
ABCDEFGH_JKLMNOPQRSTUVWXYZ // I
_BCDEFGHIJKLMNOPQRSTUVWXYZ // AL
_
ABCDEFGHIJKLMN_PQRSTUVWXYZ
ABCDE_GHIJKLMNOPQRSTUVWXYZ // OF
_
ABCDEFGHIJKLM_OPQRSTUVWXYZ // N
,
_
ABCDEFGHIJKL_N_PQRSTUVWXYZ // MO
ABC_EFGHIJKLMNOPQRST_VWXYZ // DU
ABCDEFGHIJK_MN_PQRSTUVWXYZ // LO
_
ABCDEFGHIJKL_NOPQRSTUVWXYZ // M
. 

*/

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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    if (n >= m) {
        std::cout << 0 << std::endl;
        return 0;
    }
    int ans = 1;
    Rep(i, n+1) {
        ans = (ans * i) % m;
    }
    std::cout << ans << std::endl;

    return 0;
}
