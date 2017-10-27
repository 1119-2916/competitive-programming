#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 1010001000
#define min(a, b) a>b?b:a
#define max(a, b) a>b?a:b

typedef struct st{
    int pos;
    int hi;
}st;

int n;
st data[100002];

int cmp(const void *a, const void *b)
{
    st tmp1 = *(st *)a;
    st tmp2 = *(st *)b;

    int tmp3 = tmp1.hi;
    int tmp4 = tmp2.hi;

    return tmp3 - tmp4;
}

int main(void)
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i].hi);
        data[i].pos = i+1;
    }
    qsort(data, n, sizeof(st), cmp);
    for (i = n-1; i >= 0; i--) {
        printf("%d\n", data[i].pos);
    }
    return 0;
}


