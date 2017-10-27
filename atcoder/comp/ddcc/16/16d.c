#include <stdio.h>

int n, m, k;
int a[55], b[55];
long long int max;

int main(void) 
{
    int i, j, ap = 0, bp = 0, apt, bpt;

    scanf("%d %d %d",&n, &m, &k);

    if (k != 1) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        ap += a[i];
    }

    for (i = 0; i < m; i++) {
        scanf("%d",&b[i]);
        bp += b[i];
    }

    apt = ap;
    bpt = bp;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            apt -= a[i];
            bpt -= b[j];
            apt += b[j];
            bpt += a[i];
            if (max < apt * bpt) {
                max = apt * bpt;
            }
            bpt = bp;
            apt = ap;
        }
    }

    printf("%lld\n",max);

    return 0;
}
            

