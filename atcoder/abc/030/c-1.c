#include <stdio.h>
#define MAX_AIR 100000
#define MAX(a, b) a < b ? b : a

long long int n, m, x, y, now;

int search(int a[], int now, int s, int f);

int main(void)
{
    int a[MAX_AIR], b[MAX_AIR];
    int i, j, count = 0, tmp, s, f, flag = 0;

    scanf("%lld %lld %lld %lld",&n, &m, &x, &y);
    for (i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    for (i = 0; i < m; i++) {
        scanf("%d",&b[i]);
    }

    s = 0, f = 0;
    while (1) {
        while (1) {
            if (a[s] >= now) {
                now = a[s] + x;
                break;
            }
            s++;
            if (s >= n) {
                flag = 1;
                break;
            }
        }
        printf("%lld\n",now);

        if (flag) {
            break;
        }

        while (1) {
            if (b[f] >= now) {
                now = b[f] + y;
                break;
            }
            f++;
            if (f >= m) {
                flag = 1;
                break;
            }
        }
        printf("%lld\n",now);

        if (flag) {
            break;
        }

        count++;
    }
    printf("%d\n",count);

    return 0;
}

