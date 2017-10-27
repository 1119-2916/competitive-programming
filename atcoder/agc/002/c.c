#include <stdio.h>

long long int len;
int ans[100001], data[100000];

int main(void)
{
    int n, i, j, l, count, min, max;

    scanf("%d %d", &n, &l);

    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        len += data[i];
    }

    min = 1;
    max = n-1;
    i = 0;

    while (len >= l && i < n-1) {
        if (data[min-1] < data[max]) {
            ans[i++] = min;
            len -= data[min-1];
            min++;
        } else {
            ans[i++] = max;
            len -= data[max];
            max--;
        }
    }

    if (i != n-1) {
        puts("Impossible");
    } else {
        puts("Possible");
        for (i = 0; i < n-1; i++) {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}



