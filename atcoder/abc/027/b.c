#include <stdio.h>

int island[100];
int n, ans;

int main(void)
{
    int i, count, now;

    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        scanf("%d",&island[i]);
        ans += island[i];
    }

    if (ans % n) {
        puts("-1");
        return 0;
    }

    ans /= n;

    i = 0;
    now = 0;
    while (1) {
        if (i == n) {
            break;
        }
        now += ans - island[i];
        if (now != 0) {
            count++;
        }
        i++;
    }
    printf("%d\n",count);
    return 0;
}



