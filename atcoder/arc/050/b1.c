#include <stdio.h>

long long int r, b;
long long int r1, b1;
long long int x, y;

long long int min( long long int a, long long int b);

int main(void)
{
    long long int i, j, ans = 0, tmp;

    scanf("%lld %lld",&r, &b);
    scanf("%lld %lld",&x, &y);

    for (i = 0; i <= min(r,b); i++) {
        tmp = 0;
        r1 = r; b1 = b;
        r1 -= x*i; b1 -= i;
        tmp += i;
        b1 /= y;
        if (b1 > r1) {
            tmp += r1;
        } else {
            tmp += b1;
        }
        if (tmp > ans) {
            ans = tmp;
        } 
    }

    printf("%lld\n",ans);
    return 0;
}

long long int min( long long int a, long long int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
    
