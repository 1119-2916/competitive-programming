#include <stdio.h>
#include <immintrin.h>

int main(void)
{
    int n; scanf("%d", &n);
    int *a, *b;
    a = (int *)_mm_malloc(200000, 256);
    b = (int *)_mm_malloc(200000, 256);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    _mm_free(a);
    _mm_free(b);
    return 0;
}

