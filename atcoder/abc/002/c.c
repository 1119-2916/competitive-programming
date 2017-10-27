#include <stdio.h>

int main(void)
{
    int ax, ay, bx, by, cx, cy;
    int ans;
    double ans_a;

    scanf("%d %d %d %d %d %d",&ax, &ay, &bx, &by, &cx, &cy);

    ans = ax*(by-cy)+bx*(cy-ay)+cx*(ay-by);

    if (ans < 0) {
        ans *= -1;
    }

    ans_a = (double)ans / 2;

    printf("%lf\n",ans_a);

    return 0;
}
