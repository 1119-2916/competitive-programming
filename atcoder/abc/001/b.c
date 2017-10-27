#include <stdio.h>

int main(void)
{
    int m, ans;
    scanf("%d",&m);
    if (m < 100) {
        puts("00");
    } else if (m <= 5000) {
        ans = m / 100;
        if (ans < 10) {
            printf("0%d\n",ans);
        } else {
            printf("%d\n",ans);
        }
    } else if (m <= 30000) {
        ans = m / 1000 + 50;
        printf("%d\n",ans);
    } else if (m <= 70000) {
        ans = (m / 1000 - 30) / 5 + 80;
        printf("%d\n",ans);
    } else {
        puts("89");
    }
    return 0;
}
