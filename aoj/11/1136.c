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
double distance(point a, point b);
point sum_vector(point a, point b);
point diff_vector(point a, point b);
point minus_vector(point a);
point prod_vector(point a, double t);
double dot(point a, point b);
double cross(point a, point b);
int ccw(line a, point p);
double fmin(double a, double b);

int check(int mt, int mf);
int check2(int mt, int mf);

point t[10];
point f[10];

int main(void)
{
    int n, i, j, mt, mf;
    scanf("%d", &n);
    while (n) {
        scanf("%d", &mt);
        for (i = 0; i < mt; i++) {
            scanf("%lf %lf", &t[i].x, &t[i].y);
        }
        for (i = 1; i <= n; i++) {
            scanf("%d", &mf);
            for (j = 0; j < mf; j++) {
                scanf("%lf %lf", &f[j].x, &f[j].y);
            }
            if (check(mt, mf) || check2(mt, mf)) {
                printf("%d\n", i);
            }
        }
        puts("+++++");
        scanf("%d", &n);
    }
    return 0;
}

int check(int mt, int mf)
{
    line a;
    int i, j, ccwt, ccwf;
    double lent, lenf;
    if (mt != mf) {
        return 0;
    }
    for (i = 0; i < mf; i++) {
        lent = distance(t[i], t[(i+1)%mf]);
        lenf = distance(f[i], f[(i+1)%mf]);
        if (fabs(lent - lenf) > EPS) {
            return 0;
        }
    }
    for (i = 0; i < mf; i++) {
        a.st = t[(i-1+mf)%mf];
        a.en = t[i];
        ccwt = ccw(a, t[(i+1)%mf]);
        a.st = f[(i-1+mf)%mf];
        a.en = f[i];
        ccwf = ccw(a, f[(i+1)%mf]);
        //printf("%d %d\n", ccwt, ccwf);
        if (ccwt != ccwf) {
            
            return 0;
        }
    }
    return 1;
}

int check2(int mt, int mf)
{
    line a;
    int i, j, ccwt, ccwf;
    double lent, lenf;
 
    for (i = 0; i < mf; i++) {
        lent = distance(t[i], t[(i+1)%mf]);
        lenf = distance(f[mf-i-1], f[mf-((i+1)%mf)-1]);
        if ((lent - lenf) > EPS) {
            return 0;
        }
    }
    for (i = 0; i < mf; i++) {
        a.st = t[(i-1+mf)%mf];
        a.en = t[i];
        ccwt = ccw(a, t[(i+1)%mf]);
        a.st = f[mf-1-((i-1+mf)%mf)];
        a.en = f[mf-1-i];
        ccwf = ccw(a, f[mf-1-((i+1)%mf)]);
        if (ccwt != ccwf) {
            return 0;
        }
    }
    return 1;
}

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

double distance(point a, point b)
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

