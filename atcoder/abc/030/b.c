#include <stdio.h>
#include <math.h>

int main(void) 
{
    int n, m;
    double nk, mk, ans;

    scanf("%d %d",&n, &m);

    nk = (360 / 12) * (n % 12);
    nk += 0.5 * (double)m;
    mk = (360 / 60) * m;

    if (nk < mk) {
        ans = mk - nk;
    } else {
        ans = nk - mk;
    }

    if (ans > 180) {
        printf("%lf\n",360 - ans);
    } else {
        printf("%lf\n",ans);
    }
    return 0;
}
