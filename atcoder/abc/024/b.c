#include <stdio.h>

int n, t;
long long int ans;

int main(void)
{
    int i, j;
    int bef, tmp;

    scanf("%d %d",&n, &t);

    scanf("%d",&bef);
    for (i = 1; i < n; i++) {
        scanf("%d",&tmp);
        if (bef + t <= tmp) {
            ans += t;
        } else {
            ans += (tmp - bef);
        }
        bef = tmp;
    }
    printf("%lld\n",ans + t);
    return 0;
}

