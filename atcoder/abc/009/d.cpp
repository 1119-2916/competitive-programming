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
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dij geo2 kruskal graph uf lca BIT

typedef unsigned long long Num;
struct Matrix {
	vector< vector< Num > > v, w;
	Matrix() {}
	Matrix(int n, int m) :v(n, vector<Num>(m)) { }
	inline int height()const { return (int)v.size(); }
	inline int width()const { return (int)v[0].size(); }
	inline Num& at(int i, int j) { return v[i][j]; }
	inline const Num& at(int i, int j)const { return v[i][j]; }
	static Matrix identity(int n) {
		Matrix A(n, n);
		for (int i = 0; i < n; i++) A.at(i, i) = ~0U;
		return A;
	}
	inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
	Matrix &operator*=(const Matrix& B) {
		int n = height(), m = B.width(), p = B.height();
		assert(p == width());
		w.assign(n, vector<Num>(m, 0));
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
			Num x = 0;
			for (int k = 0; k < p; k++)
				x ^= at(i, k) & B.at(k, j);
			w[i][j] = x;
		}
		v.swap(w);
		return *this;
	}
};
Matrix operator^(const Matrix &m, long long exponent) {
	Matrix A = m, B = Matrix::identity(m);
	while (exponent) {
		if (exponent & 1) B *= A;
		A *= A;
		exponent >>= 1;
	}
	return B;
}
 
signed main() {
    int2(k, m);
    vi a(k), c(k);
    rep(i, k) cin >> a[i];
    rep(i, k) cin >> c[i];

	Matrix funami(k, k);
    rep(i, k) {
        funami.at(0, i) = c[i];
    }
    rep(i, k-1) {
        funami.at(i+1, i) = ~0U;
    }
	Matrix toshino(k, 1);
    rep(i, k) {
        toshino.at(i, 0) = a[k-1-i];
    }
    if (m - k > 0) {
        funami = funami ^ (m - k);
        funami *= toshino;
        std::cout << funami.at(0, 0) << std::endl;
    } else {
        std::cout << a[m-1] << std::endl;
	}
	return 0;
}

/*
 * 結合法則、分配法則、可換(+)、単位元0, 1を持つ和積を備える(半環)
 */
using Num = unsigned long long;
struct Matrix {
vector< vector< Num > > v, w;
Matrix() {}
Matrix(int n, int m) :v(n, vector<Num>(m)) { }
inline int height()const { return (int)v.size(); }
inline int width()const { return (int)v[0].size(); }
inline Num& at(int i, int j) { return v[i][j]; }
inline const Num& at(int i, int j)const { return v[i][j]; }
static Matrix identity(int n) {
    Matrix A(n, n);
    for (int i = 0; i < n; i++) A.at(i, i) = 1;
    return A;
}
inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
Matrix &operator*=(const Matrix& B) {
    int n = height(), m = B.width(), p = B.height();
    assert(p == width());
    w.assign(n, vector<Num>(m, 0));
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
        Num x = 0;
        for (int k = 0; k < p; k++)
            x += at(i, k) * B.at(k, j);
        w[i][j] = x;
    }
    v.swap(w);
    return *this;
}
};
Matrix operator^(const Matrix &m, long long exponent) {
Matrix A = m, B = Matrix::identity(m);
while (exponent) {
    if (exponent & 1) B *= A;
    A *= A;
    exponent >>= 1;
}
return B;
}

