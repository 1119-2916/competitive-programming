#include <stdio.h>

int main(void) {
    int ans, n, x;
    scanf("%d %d",&n, &x);
    ans = n * 525;
    ans += x * 15;
    printf("%d\n",ans);
    return 0;
}
