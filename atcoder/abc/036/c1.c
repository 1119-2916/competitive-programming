#include <stdio.h>
#include <stdlib.h>

int n, input[100001], ans[100001];

int main(void)
{
    int i, j, tmp, count;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d",&input[i]);
    }
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < i; j++) {
            if (input[i] < input[j]) {
                ans[j]++;
            } else if (input[i] > input[j]) {
                count++;
            }
        }
        ans[i] = count;
    }

    for (i = 0; i < n; i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}

int cmpInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}


