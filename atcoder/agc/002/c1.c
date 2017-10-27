#include <stdio.h>

int n, len, str[100001];

int main(void)
{
    int i, fl = 0;

    scanf("%d %d", &n, &len);

    for (i = 0; i < n; i++) {
        scanf("%d", &str[i]);
    }

    for (i = 0; i < n-1; i++) {
        if (str[i] + str[i+1] >= len) {
            fl = i+1;
            break;
        }
    }

    if (fl) {
        puts("Possible");
        for (i = 1; i < fl; i++) {
            printf("%d\n", i);
        }
        for (i = n-1; i > fl; i--) {
            printf("%d\n", i);
        }
        printf("%d\n", fl);
    } else {
        puts("Impossible");
    }

    return 0;
}
            


