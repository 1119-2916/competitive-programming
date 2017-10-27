#include <stdio.h>

int main(void)
{
    int l, x, y, s, d;
    double x1, x2;
    double ans1, ans2;
    scanf("%d %d %d %d %d",&l, &x, &y, &s, &d);
    if (s < d) {
        x1 = d - s;
        x2 = l - d + s;
    } else {
        x1 = l - s + d;
        x2 = s - d;
    }
    ans1 = x1 / (y + x);
    if (x != y) {
        ans2 = x2 / (y - x);
    } else {
        ans2 = -1.0;
    }

    if (ans2 < 0) {
        printf("%lf\n",ans1);
    } else if (ans2 < ans1) {
        printf("%lf\n",ans2);
    } else {
        printf("%lf\n",ans1);
    }
    return 0;
}
