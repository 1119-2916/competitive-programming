#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
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
// cmd

const double EPS = 1e-8;
const double PI = acos(-1);

struct Point { 
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    double norm() { return x*x + y*y; }
    double abs() { return sqrt(norm()); }

    Point &operator+=(const Point &p) { x += p.x; y += p.y; return *this; }
    Point &operator-=(const Point &p) { x -= p.x; y -= p.y; return *this; }
    Point &operator*=(double a) { x *= a; y *= a; return *this; }
    Point &operator/=(double a) { x /= a; y /= a; return *this; }
};

Point operator+(const Point &p1, const Point &p2) { return Point(p1) += p2; }
Point operator-(const Point &p1, const Point &p2) { return Point(p1) -= p2; }
Point operator*(const Point &p1, double a) { return Point(p1) *= a; }
Point operator/(const Point &p1, double a) { return Point(p1) /= a; }

bool operator<(const Point &p1, const Point &p2) {
    return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y;
}
bool operator>(const Point &p1, const Point p2) { return p2 < p1; }

inline istream &operator >> (istream &is, Point &p) { double x, y; is >> x >> y; p = Point(x, y); return is;}
inline ostream &operator << (ostream &os, const Point &p) { os << p.x << ' ' << p.y; return os;}

struct Vector :public Point {
    using Point::Point;
    Vector() {}
    Vector(const Point &P) { x = P.x; y = P.y; }
};

double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

struct Line {
    Point p1, p2;
    Line() {}
    Line(Point p1, Point p2) :p1(p1), p2(p2) {}
};

struct Segment : public Line {
    using Line::Line;
    Segment() {}
    Segment(const Line &L) { p1 = L.p1; p2 = L.p2; }
    Vector vec() { return p2 - p1; }
};

struct Circle {
    Point c;
    double r;
    Circle() {}
    Circle(Point c, double r) : c(c), r(r) {}
};
using Polygon = vector<Point>;

double arg(Vector p) { return atan2(p.y, p.x); }

Vector polar(double r, double a) { return Point(cos(a) * r, sin(a) * r); }

enum { ONLINE_FRONT = -2, CLOCKWISE, ON_SEGMENT, COUNTER_CLOCKWISE, ONLINE_BACK };
int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0, b = p2 - p0;
    if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if (cross(a,b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (a.norm() < b.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}

double get_distance(Point a, Point b) { return (a - b).abs(); }

double get_distance(Line l, Point p) { 
    return abs(cross(l.p2 - l.p1, p - l.p1) / (l.p2 - l.p1).abs());
}

double get_distance(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return (p - s.p1).abs();
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return (p - s.p2).abs();
    return get_distance(Line(s), p);
}

bool intersect(Circle c, Line l) { 
    return get_distance(l, c.c) <= c.r + EPS;
}

bool intersect(Circle c, Segment s) {
    return get_distance(s, c.c) <= c.r + EPS;
}

bool intersect(Circle c1, Circle c2) {
    double d = get_distance(c1.c, c2.c);
    if (d > c1.r + c2.r) return false;
    else return true;
}

enum { OUT = 0, ON = 2, IN = 1 };
int contains(const Polygon &pl, Point p) {
    int n = pl.size();
    bool x = false;
    for (int i = 0; i < n; i++) {
        Point a = pl[i] - p, b = pl[(i + 1) % n] - p;
        if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return ON;
        if (a.y > b.y) swap(a, b);
        if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
    }
    return (x ? IN : OUT);
}

Polygon convex_hull(Polygon P) {
    sort(P.begin(), P.end());
    Polygon up;
    for (Point &p : P) {
        while (up.size() > 1 && ccw(up[up.size() - 2], up[up.size() - 1], p) != CLOCKWISE) up.pop_back();
        up.emplace_back(p);
    }
    Polygon down;
    for (Point &p : P) {
        while (down.size() > 1 && ccw(down[down.size() - 2], down[down.size() - 1], p) != COUNTER_CLOCKWISE) down.pop_back();
        down.emplace_back(p);
    }
    reverse(up.begin(), up.end());
    down.insert(down.end(), up.begin() + 1, up.end() - 1);
    return down;
}

Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}

pair<Point, Point> get_cross_points(Circle c, Line l) {
    assert(intersect(c, l));
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();
    double base = sqrt(c.r * c.r - (pr - c.c).norm());
    return make_pair(pr + e * base, pr - e * base);
}

pair<Point, Point> get_cross_points(Circle c1, Circle c2) {
    int m = intersect(c1, c2);
    assert(m != 4 && m != 0);
    double d = (c1.c - c2.c).abs();
    double a = acos((c1.r * c1.r - c2.r * c2.r + d*d) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t-a));
}

Line get_bisection(const Point &p1, const Point &p2) {
    Circle c1(p1, 10000.0), c2(p2, 10000.0);
    auto ps = get_cross_points(c1, c2);
    return Line(ps.first, ps.second);
}

Polygon get_square(const Circle &c1, const Circle &c2) {
    double dx = (c1.c.x - c2.c.x) * 2, dy = (c1.c.y - c2.c.y) * 2;
    Point nc1(c1.c.x + dx, c1.c.y + dy), nc2(c2.c.x - dx, c2.c.y - dy);
    Line mid_line(nc1, nc2);
    auto p1 = get_cross_points(c1, mid_line), p2 = get_cross_points(c2, mid_line);
    auto l1 = get_bisection(p1.first, p1.second), l2 = get_bisection(p2.first, p2.second);
    auto ans1 = get_cross_points(c1, l1), ans2 = get_cross_points(c2, l2);
    Polygon ret; 
    ret.push_back(ans1.first);
    ret.push_back(ans1.second);
    ret.push_back(ans2.first);
    ret.push_back(ans2.second);
    return convex_hull(ret);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<Circle> from(n), to(n);
    vector<Polygon> square(n);
    rep(i, n) {
        double r, a, b, c, d;
        cin >> r >> a >> b >> c >> d;
        from[i] = Circle(Point(a, b), r);
        to[i] = Circle(Point(c, d), r);
        square[i] = get_square(from[i], to[i]);
    }

    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    rep(i, dp.size()) {
        if (dp[i] != -1) {
            rep(j, n) {
                if (i & (1 << j)) continue;
                bool fl = false;
                rep(k, n) {
                    if (j == k) continue;
                    if (i & (1 << k)) {
                        fl |= intersect(to[j], to[k]);
                        fl |= contains(square[j], to[k].c);
                        rep(ptr, square[j].size()) {
                            fl |= intersect(to[k], Segment(square[j][ptr], square[j][(ptr+1) % square[j].size()]));
                        }
                    } else {
                        fl |= intersect(to[j], from[k]);
                        fl |= contains(square[j], from[k].c);
                        rep(ptr, square[j].size()) {
                            fl |= intersect(from[k], Segment(square[j][ptr], square[j][(ptr+1) % square[j].size()]));
                        }
                    }
                }
                if (!fl) {
                    dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + 1);
                }
            }
        }
    }

    int ans = 0;
    rep(i, dp.size()) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}



