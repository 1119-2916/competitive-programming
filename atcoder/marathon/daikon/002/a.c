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
    for (count = 0; count < 100; count++) {
        ans = 1;
        while (1) {
            while (prim[p]) {
                p++;
            }
            if (ans * p < 1000000000) {
                ans *= p++;
            } else {
                break;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
