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
double dot(point a, point b);
double prod(point a, point b);

point reflection(line a, point p);
point projection(line a, point p);
int ccw(line a, point p);

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

double prod(point a, point b)
{
    //外積
    return (a.x * b.y) - (b.x * a.y);
}

int ccw(line a, point p)
{
    //counter clockwise == 1
    //clockwise == 2
    //online back == 3
    //online front == 4
    //on segment == 5
    int cls = prod(diff_vector(a.en, a.st), diff_vector(p, a.st));
    if (cls > 0) {
        return 1;
    } else if (cls < 0) {
        return 2;
    } else if (dot(diff_vector(a.en, a.st), diff_vector(p, a.st)) < 0) {
        return 3;
    } else if (norm(diff_vector(a.st, a.en)) < norm(diff_vector(a.st, p))) {
        return 4;
    } else {
        return 5;
    }
}

///////////////////////////////////////

int main(void)
{
    point p;
    line ab;
    int n, i, a;

    scanf("%lf%lf%lf%lf%d", &ab.st.x, &ab.st.y, &ab.en.x, &ab.en.y, &n);
    for (i = 0; i < n; i++) {
        scanf("%lf%lf", &p.x, &p.y);
        a = ccw(ab, p);
        if (a == 1) {
            puts("COUNTER_CLOCKWISE");
        } else if (a == 2) {
            puts("CLOCKWISE");
        } else if (a == 3) {
            puts("ONLINE_BACK");
        } else if (a == 4) {
            puts("ONLINE_FRONT");
        } else {
            puts("ON_SEGMENT");
        }
    }
    return 0;
}

