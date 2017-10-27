#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

using namespace std;

#define INF 1001000100010001000
#define INFd 1010001000.0
#define MOD 1000000007
#define int long long
#define double long double
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
#define Edge pair< int, i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define next(P,i) P[(i+1)%P.size()]
#define prev(P,i) P[(i+P.size()-1)%P.size()]
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

const double EPS = 1e-8;

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) :x(x), y(y) {}

	Point &operator+=(const Point &p) { x += p.x; y += p.y; return *this; }
	Point &operator-=(const Point &p) { x -= p.x; y -= p.y; return *this; }
	Point &operator*=(double a) { x *= a; y *= a; return *this; }
	Point &operator/=(double a) { x /= a; y /= a; return *this; }

	double abs() { return sqrt(norm()); }
	double norm() { return x*x + y*y; }
};
Point operator+(const Point &p1, const Point &p2) { return Point(p1) += p2; }
Point operator-(const Point &p1, const Point &p2) { return Point(p1) -= p2; }
Point operator*(const Point &p, double a) { return Point(p) *= a; }
Point operator/(const Point &p, double a) { return Point(p) /= a; }
bool operator==(const Point &p1, const Point &p2) { return equals(p1.x, p2.x) && equals(p1.y, p2.y); }
bool operator<(const Point &p1, const Point &p2) {
	//return p1.y != p2.y ? p1.y < p2.y : p1.x < p2.x; //y昇順 -> x昇順
	return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y; //x昇順 -> y昇順
}
bool operator>(const Point &p1, const Point &p2) { return p2 < p1; }
inline istream &operator >> (istream &is, Point &p) { double x, y; is >> x >> y; p = Point(x, y); return is; }
inline ostream &operator << (ostream &os, const Point &p) { os << p.x << ' ' << p.y; return os; }

struct Circle {
	Point c; //center
	double r; //radius
	Circle() {}
	Circle(Point c, double r) :c(c), r(r) {}
};

//2点間の距離
double get_distance(Point a, Point b) { return (a - b).abs(); }

//点の内包
int contains(Circle c, Point p) {
	double d = get_distance(c.c, p);
	if (equals(d, c.r))return 1;
	if (d < c.r)return 1;
	return 0;
}


signed main()
{
    int n;
    double r;
    int casenum = 1;
    while (scanf("%lld%Lf", &n, &r), n) {
        vector< Point >  yui(n);
        rep(i, n) {
            double a, b;
            scanf("%Lf %Lf", &a, &b);
            yui[i] = Point(a, b);
            //cin >> yui[i];
            yui[i].y *= -1;
        }
        sort(all(yui));
        bool cirfalse = false;
        rep(i, yui.size()) {
            yui[i].y *= -1;
            //cout << yui[i] << endl;
            if (yui[i].y - r > EPS) {
                cout << "Case " << casenum << ": ";
                casenum++;
                cout << -1 << endl;
                cirfalse = true;
                break;
            }
        }
        if (cirfalse) continue;
        vb inner(n, false);
        bool stop = true;
        int ans = 0, ptr = 0;
        while (stop) {
            stop = false;

            Point cent(INFd, INFd);
            rep(i, n) {
                if (!inner[i]) {
                    Point tmp(yui[i].x+sqrt(r*r-yui[i].y*yui[i].y), 0);
                    //cout << tmp << endl;
                    if (tmp < cent) {
                        cent = tmp;
                    }
                }
            }
            //cout << cent << endl;

            rep(i, n) {
                if (!inner[i]) {
                    if (contains(Circle(cent, r), yui[i])) {
                        inner[i] = true;
                    } else {
                        stop = true;
                    }
                }
            }
            ans++;
        }
        printf("Case %lld: %lld\n", casenum, ans);
        /*
        cout << "Case " << casenum << ": ";
        cout << ans << endl;
        */
        casenum++;
    }

    return 0;
}




