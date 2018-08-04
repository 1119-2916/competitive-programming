#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fir first
#define sec second;
#define pii pair<int, int>
#define mp make_pair
#define pb emplace_back
   
//#define double long double
const double EPS = 1e-8;
const double PI = acos(-1);
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define next(P,i) P[(i+1)%P.size()]
#define prev(P,i) P[(i+P.size()-1)%P.size()]

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

struct Vector :public Point {
    using Point::Point;
    Vector() {}
    Vector(const Point &P) { x = P.x; y = P.y; }
    Vector rotate(double rad) { return Vector(x*cos(rad) - y*sin(rad), x*sin(rad) + y*cos(rad)); }
    Vector unit() { return *this / abs(); }
};

//内積 dot product
double dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
//外積 cross product の大きさ（正負あり）
double cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }

struct Line {
    Point p1, p2;
    Line() {}
    Line(Point p1, Point p2) :p1(p1), p2(p2) {}
};

struct Segment :public Line {
    using Line::Line;
    Segment() {}
    Segment(const Line &L) { p1 = L.p1; p2 = L.p2; }
    Vector vec() { return p2 - p1; }
};

using Polygon = vector<Point>;


//2つのベクトルの角度
double angle(Vector a, Vector b) {
    double lena = a.abs(), lenb = b.abs();
    if (lena == 0 || lenb == 0)return 0; //解なし
    double costheta = dot(a, b) / (lena*lenb);
    if (equals(costheta, 1))costheta = 1; //誤差対策
    return acos(costheta);
}

bool inrange(Point p, double x1, double y1, double x2, double y2) {
    return x1 <= p.x&&p.x <= x2&&y1 <= p.y&&p.y <= y2;
}

//直交判定
bool is_orthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool is_orthogonal(Segment s1, Segment s2) { return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }

//平行判定
bool is_parallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool is_parallel(Segment s1, Segment s2) { return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }

//射影
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base*r;
}
//反射
Point reflect(Segment s, Point p) { return p + (project(s, p) - p)*2.0; }

//線分(p0,p1)に対するp2の位置関係
enum { ONLINE_FRONT = -2, CLOCKWISE, ON_SEGMENT, COUNTER_CLOCKWISE, ONLINE_BACK };
int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0, b = p2 - p0;
    if (cross(a, b) > EPS)return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS)return CLOCKWISE;
    if (dot(a, b) < -EPS)return ONLINE_BACK; //p2 p0 p1
    if (a.norm() < b.norm())return ONLINE_FRONT; //p0 p1 p2
    return ON_SEGMENT;
}
int ccw(Vector a, Vector b) {
    if (cross(a, b) > EPS)return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS)return CLOCKWISE;
    if (dot(a, b) < -EPS)return ONLINE_BACK; //p2 p0 p1
    if (a.norm() < b.norm())return ONLINE_FRONT; //p0 p1 p2
    return ON_SEGMENT;
}

//直線と直線の交差判定
bool intersect(Segment a, Segment b) {
    Point p1 = a.p1, p2 = a.p2, p3 = b.p1, p4 = b.p2;
    if (p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4) return false;
    return (ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1)*ccw(p3, p4, p2) <= 0);
}
//(交差判定続く)

//2点間の距離
double get_distance(Point a, Point b) { return (a - b).abs(); }

//直線と点の距離
double get_distance(Line l, Point p) { return abs(cross(l.p2 - l.p1, p - l.p1) / (l.p2 - l.p1).abs()); }

//線分と点の距離
double get_distance(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0)return (p - s.p1).abs();
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0)return (p - s.p2).abs();
    return get_distance(Line(s), p);
}

//線分と線分の距離
double get_distance(Segment s1, Segment s2) {
    if (intersect(s1, s2))return 0.0;
    return	min(
            min(get_distance(s1, s2.p1), get_distance(s1, s2.p2)),
            min(get_distance(s2, s1.p1), get_distance(s2, s1.p2))
            );
}


//線分と線分の交点
Point get_cross_point(Segment a, Segment b) {
    assert(intersect(a, b));
    Vector base = b.p2 - b.p1;
    double area1 = abs(cross(base, a.p1 - b.p1));
    double area2 = abs(cross(base, a.p2 - b.p1));
    double t = area1 / (area1 + area2);
    return a.p1 + (a.p2 - a.p1)*t;
}

//点の内包
enum { OUT = 0, ON, IN };
int contains(const Polygon &pl, Point p) {
    int n = pl.size();
    bool x = false;
    for (int i = 0; i < n; i++) {
        Point a = pl[i] - p, b = pl[(i + 1) % n] - p;
        if (abs(cross(a, b)) < EPS&&dot(a, b) < EPS)return ON;
        if (a.y > b.y)swap(a, b);
        if (a.y < EPS&&EPS<b.y&&cross(a, b)>EPS)x = !x;
    }
    return (x ? IN : OUT);
}

struct Square {
    // 反時計周り
    Point p1, p2, p3, p4;
    Segment l1, l2, l3, l4;
    Square() {}
    Square(Point p1, Point p2, Point p3, Point p4) 
        :p1(p1), p2(p2), p3(p3), p4(p4)
    {
        l1 = Segment(Line(p1, p2));
        l2 = Segment(Line(p2, p3));
        l3 = Segment(Line(p4, p3));
        l4 = Segment(Line(p1, p4));
    }
    Polygon to_Polygon() {
        Polygon ret(0);
        ret.pb(p1);
        ret.pb(p2);
        ret.pb(p3);
        ret.pb(p4);
        return ret;
    }
};

bool operator==(const Square &s1, const Square &s2) {
    return s1.p1 == s2.p1 && s1.p2 == s2.p2 && 
        s1.p3 == s2.p3 && s1.p4 == s2.p4;
}

int cross_rects(Square &s1, Square &s2)
{
    int ret = 0;
    ret += (intersect(s1.l2, s2.l1) ? 1 : 0);
    ret += (intersect(s1.l4, s2.l1) ? 1 : 0);
    ret += (intersect(s1.l1, s2.l2) ? 1 : 0);
    ret += (intersect(s1.l3, s2.l2) ? 1 : 0);
    ret += (intersect(s1.l2, s2.l3) ? 1 : 0);
    ret += (intersect(s1.l4, s2.l3) ? 1 : 0);
    ret += (intersect(s1.l1, s2.l4) ? 1 : 0);
    ret += (intersect(s1.l3, s2.l4) ? 1 : 0);
    //cout << ret << endl;
    return ret / 2;
}

void add_point(vector<Point> &points, Square &s1, Square &s2)
{
    if (intersect(s1.l2, s2.l1))
        points.pb(get_cross_point(Segment(s1.l2), Segment(s2.l1)));
    if (intersect(s1.l4, s2.l1))
        points.pb(get_cross_point(Segment(s1.l4), Segment(s2.l1)));
    if (intersect(s1.l1, s2.l2))
        points.pb(get_cross_point(Segment(s1.l1), Segment(s2.l2)));
    if (intersect(s1.l3, s2.l2))
        points.pb(get_cross_point(Segment(s1.l3), Segment(s2.l2)));
    if (intersect(s1.l2, s2.l3))
        points.pb(get_cross_point(Segment(s1.l2), Segment(s2.l3)));
    if (intersect(s1.l4, s2.l3))
        points.pb(get_cross_point(Segment(s1.l4), Segment(s2.l3)));
    if (intersect(s1.l1, s2.l4))
        points.pb(get_cross_point(Segment(s1.l1), Segment(s2.l4)));
    if (intersect(s1.l3, s2.l4))
        points.pb(get_cross_point(Segment(s1.l3), Segment(s2.l4)));
}

signed main()
{
    int n;
    while (cin >> n, n) {
        vector<Square> squares(0);
        vector<Point> points(0);
        int ans = 1;
        rep(i, n) {
            double a, b, c, d;
            cin >> a >> b >> c >> d;
            Point p1(a, b), p2(a, d), p3(c, d), p4(c, b);
            cout << a << b << c << d << endl;
            Square input(p1, p2, p3, p4);
            bool fl = false;
            rep(j, squares.size()) fl |= (input == squares[j]);
            if (fl) continue;
            ans++;
            rep(j, squares.size()) {
                ans += cross_rects(squares[j], input);
            }
            rep(j, points.size()) {
                ans += 
                  (contains(input.to_Polygon(), points[j]) == IN) ? 1 : 0;
            }
            rep(j, squares.size()) {
                add_point(points, squares[j], input);
            }
            squares.pb(input);
            cout << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}


