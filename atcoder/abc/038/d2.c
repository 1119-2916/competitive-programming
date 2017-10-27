#include <stdio.h>
#include <stdlib.h>

struct solve{
    int x, y;
};

int cmp_x(const void *a, const void *b);
struct solve data[100000];
int node[100000], n;

int main(void)
{
    int i, j, max;
    scanf("%d",&n);
    if (n > 10000) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%d %d", &data[i].x, &data[i].y);
        node[i] = 1;
    }
    max = 1;
    qsort(data, n, sizeof(struct solve), cmp_x);
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            if (data[i].x < data[j].x && data[i].y < data[j].y) {
                node[j] = node[i] + 1;
                if (max < node[j]) {
                    max = node[j];
                }
            }
        }
    }
    printf("%d\n",max);
    return 0;
}

int cmp_x(const void *a, const void *b) 
{
    struct solve s1 = *(struct solve *) a;
    struct solve s2 = *(struct solve *) b;

    int t1 = s1.x;
    int t2 = s2.x;
    int t3 = s1.y;
    int t4 = s2.y;
    if (t1 == t2) {
        return t4 - t3;
    } else {
        return t1 - t2;
    }
}

