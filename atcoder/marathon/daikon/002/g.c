#include <stdio.h>

int prim[1000000];

int main(void) 
{
    int i, j, p, count;
    long long int ans;

    for (i = 2; i*i < 1000000; i++) {
        for (j = 2; j*i < 1000000; j++) {
            prim[i*j] = 1;
        }
    }

    p = 2;
    for (i = 0; i < 100; i++ ) {
        ans = 1;
        while (ans * p < 1000000000) {
            ans *= p;
        }
        printf("%lld\n", ans);
        p++;
        while (prim[p]) {
            p++;
        }
    }

    return 0;
}

