#include <stdio.h>
#define MAX_DAY 10000
#define MAX_P 100

int n, d, k;
int l[MAX_DAY], r[MAX_DAY];

int main(void)
{
    int i, j, t, s, now;
    scanf("%d %d %d",&n, &d, &k);

    for (i = 0; i < d; i++) {
        scanf("%d %d",&l[i], &r[i]);
    }

    for (i = 0; i < k; i++) {
        scanf("%d %d",&s, &t);
        if (s < t) {
            now = s;
            for (j = 0; j < n; j++) {
                if (l[j] <= now && now < r[j]) {
                    now = r[j];
                }
                if (now >= t) {
                    printf("%d\n",j+1);
                    break;
                }
            }
        } else if (s == t) {
            puts("0");
        } else {
            now = s;
            for (j = 0; j < n; j++) {
                if (l[j] < now && now <= r[j]) {
                    now = l[j];
                }
                if (now <= t) {
                    printf("%d\n",j+1);
                    break;
                }
            }
        }
    }
    return 0;
}

