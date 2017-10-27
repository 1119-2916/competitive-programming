#include <stdio.h>

int prim[1000000];

int main(void) 
{
    int i, j, p1, p2, p3, p4, count;
    long long int ans;

    for (i = 2; i*i < 1000000; i++) {
        for (j = 2; j*i < 1000000; j++) {
            prim[i*j] = 1;
        }
    }

    p1 = 2;
    for (i = 0; i < 100; i++) {
        ans = 720720;
        while (ans * p1 < 100000000) {
            ans *= p1;
        }
        p1++;
        while (prim[p1]) {
            p1++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
