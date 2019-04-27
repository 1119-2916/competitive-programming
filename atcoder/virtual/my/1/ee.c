#include <stdio.h>
#include <stdlib.h>

#define ASIZE 256

#pragma GCC optimize("O3")
#pragma GCC target("avx")

int main(void)
{
    int n, nn, *a, *b;
    scanf("%d", &n);
    nn = n - (n % ASIZE);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    int dst[ASIZE], ans = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < nn/ASIZE; i++) {
            for (int j = 0; j < ASIZE; j++) {
                dst[j] = a[k] + b[i*ASIZE+j];
            }
            for (int j = 0; j < ASIZE; j++) {
                ans = ans ^ dst[j];
            }
        }
        for (int i = 0; i < n % ASIZE; i++) {
            ans ^= a[k] + b[nn+i];
        }
    }
    printf("%d\n", ans);
    free(a);
    free(b);
    return 0;
}

