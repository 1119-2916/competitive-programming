#include <stdio.h>
#define MOD 1000000007

int main(void)
{
    int wh, w, h, ans = 1;
    scanf("%d %d", &w, &h);
    wh = w+h;

    while (wh > h || w > 0) {
        if (wh > h) {
            ans *= wh--;
        }
        if (w > 0 && ans % w == 0) {
            ans /= w--;
        }
        ans %= MOD;
        printf("%d\n",ans);
    }

    return 0;
}
