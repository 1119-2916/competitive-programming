#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int input[100001];

int main(void)
{
    int a, b, i, j, n, length, ans = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &input[i]);
    }
    for (i = 1; i <= n; i++) {
        if (input[input[i]] == i) {
            ans++;
        }
    }

    printf("%d\n", ans/2);

    return 0;
}
