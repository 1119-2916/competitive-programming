#include <stdio.h>
#include <math.h>
#define EPS 0.0000000002
#define MAX 1010001000

typedef struct point{
    double x, y;
}point;

typedef struct line{
    point st, en;
}line;

double norm(point a);
double norm2(point a);
double distans(point a, point b);
point sum_vector(point a, point b);
point diff_vector(point a, point b);
point minus_vector(point a);
point prod_vector(point a, double t);
double dot(point a, point b);
double cross(point a, point b);

point reflection(line a, point p);
point projection(line a, point p);
int ccw(line a, point p);
int parallel(line a, line b);
int orthogonal(line a, line b);
int intersection(line a, line b);
point cross_point(line a, line b);
double distanceLP(line a, point b);
double distanceLL(line a, line b);

double area(int n, point ps[]);
int isConvex(int n, point ps[]);

double fmin(double a, double b);
////////////////////////////////////////////
double fmin(double a, double b)
{
    return a < b ? a : b;
}

double norm(point a)
{
    //原点からの距離
    return sqrt((a.x * a.x) + (a.y * a.y));
}

double norm2(point a)
{
    //原点からの距離の二乗
    return (a.x * a.x) + (a.y * a.y);
}

double distans(point a, point b)
{
    //二点間の距離
    point tmp = sum_vector(b, minus_vector(a));
    return norm(tmp);
}

point sum_vector(point a, point b)
{
    //ベクトルの和
    a.x += b.x;
    a.y += b.y;
    return a;
}

point diff_vector(point a, point b)
{
    //ベクトルの差
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

point prod_vector(point a, double t)
{
    //ベクトルのスカラー倍
    a.x *= t;
    a.y *= t;
    return a;
}

point minus_vector(point a)
{
    //逆ベクトル
    a.x *= -1;
    a.y *= -1;
    return a;
}

double dot(point a, point b)
{
    //内積
    return (a.x * b.x) + (a.y * b.y);
}

double cross(point a, point b)
{
    //外積
    return (a.x * b.y) - (b.x * a.y);
}

///////////////////////////////////////////
point reflection(line a, point p)
{
    //直線aについて点pと線対称な点を返す
    return sum_vector(projection(a, p), diff_vector(projection(a, p), p));
}

point projection(line a, point p)
{
    //直線ab上に点pから垂線を下ろしたときの点h//
    point h;
    double k = dot(diff_vector(a.st, p), diff_vector(a.st, a.en))
        / dot(diff_vector(a.en, a.st), diff_vector(a.en, a.st));
    h.x = k * (a.en.x - a.st.x) + a.st.x;
    h.y = k * (a.en.y - a.st.y) + a.st.y;
    return h;
}

int ccw(line a, point p)
{
    //counter clockwise == 1
    //clockwise == -1
    //online back == 2
    //online front == -2
    //on segment == 0
    int cls = cross(diff_vector(a.en, a.st), diff_vector(p, a.st));
    if (cls > 0) {
        return 1;
    } else if (cls < 0) {
        return -1;
    } else if (dot(diff_vector(a.en, a.st), diff_vector(p, a.st)) < 0) {
        return 2;
    } else if (norm(diff_vector(a.st, a.en)) < norm(diff_vector(a.st, p))) {
        return -2;
    } else {
        return 0;
    }
}

int parallel(line a, line b)
{
    //並行で1,そうでなくて0
    if (!cross(diff_vector(a.en, a.st), diff_vector(b.en, b.st))) {
        return 1;
    } else {
        return 0;
    }
}

int orthogonal(line a, line b)
{
    //直行で1,そうでなくて0
    if (!dot(diff_vector(a.en, a.st), diff_vector(b.en, b.st))) {
        return 1;
    } else {
        return 0;
    }
}

int intersection(line a, line b)
{
    //線分a, bが交差するとき1,そうでなくて0
    if (ccw(a,b.st) * ccw(a,b.en) <= 0 &&
            ccw(b,a.st) * ccw(b,a.en) <= 0) {
        return 1;
    } else {
        return 0;
    }
}

point cross_point(line a, line b)
{
    //交差する線分の交点の座標
    double c1 = cross(diff_vector(b.st, a.st), diff_vector(b.en, a.st));
    double c2 = cross(diff_vector(b.st, a.en), diff_vector(b.en, a.en));
    double t = fabs(c1) / (fabs(c1) + fabs(c2));
    return sum_vector(prod_vector(diff_vector(a.en, a.st), t), a.st);
}

double distanceLP(line a, point b)
{
    //点と線分の距離
    if (dot(diff_vector(a.en, a.st), diff_vector(b, a.st)) < 0.0) {
        return fabs(norm(diff_vector(b, a.st)));
    }
    if (dot(diff_vector(a.st, a.en), diff_vector(b, a.en)) < 0.0) {
        return fabs(norm(diff_vector(b, a.en)));
    }
    point h = projection(a, b);
    return norm(diff_vector(h, b));
}


double distanceLL(line a, line b)
{
    //線分と線分の最短距離
    double ans1, ans2, ans3, ans4;
    if (intersection(a, b)) {
        return 0.00000000000;
    } else {
        ans1 = distanceLP(a, b.st);
        ans2 = distanceLP(a, b.en);
        ans3 = distanceLP(b, a.st);
        ans4 = distanceLP(b, a.en);
    }
    return fmin(ans1, fmin(ans2, fmin(ans3, ans4)));
}

double area(int n, point ps[])
{
    //n角形の面積
    int i;
    double ans = 0.0;
    for (i = 1; i <= n; i++) {
        ans += cross(ps[i-1], ps[i%n]);
    }
    return ans/2;
}

int isConvex(int n, point ps[])
{
    //n角形が凸多角形なら１、そうでなくて０
    //ただし検証は半時計回り
    int i, tmp;
    line a;
    for (i = 0; i < n; i++) {
        a.st = ps[i];
        a.en = ps[(i+1+n)%n];
        tmp = ccw(a, ps[(i+2+n)%n]); 
        if (tmp != 1 && tmp != -2) {
            return 0;
        }
    }
    return 1;
}


///////////////////////////////////////

int main(void)
{
    point input[1000];
    double ans;
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lf%lf", &input[i].x, &input[i].y);
    }
    printf("%d\n", isConvex(n, input));
    return 0;
}

