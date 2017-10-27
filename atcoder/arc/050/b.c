#include <stdio.h>

long long int r, b;
long long int x, y;
long long int ra, ba, r1, b1;
long long int red, blue;

int main(void)
{
    long long int ans1 = 0, ans2 = 0;
    scanf("%lld %lld",&r, &b);
    scanf("%lld %lld",&x, &y);

    r1 = r;
    b1 = b;

    ra = r1/x;

    if (ra > b1) {
        r1 -= x*b1;
        b1 -= b1;
        ans1 += b1;
    } else {
        r1 -= ra*x;
        b1 -= ra;
        ans1 += ra;

        ba = b1/y;

        if (ba > r1) {
            ans1 += r1;
        } else {
            ans1 += ba;
        }
    }

    r1 = r;
    b1 = b;

    ba = b1/y;

    if (ba > r1) {
        r1 -= r1;
        b1 -= y*r1;
        ans2 += r1;
    } else {
        b1 -= ba*y;
        r1 -= ba;
        ans2 += ba;

        ra = r1/x;

        if (ra > b1) {
            ans2 += b1;
        } else {
            ans2 += ra;
        }
    }

    if (ans1 < ans2) {
        printf("%lld\n",ans2);
    } else {
        printf("%lld\n",ans1);
    } 

    return 0;
}





