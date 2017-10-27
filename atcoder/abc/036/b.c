#include <stdio.h>

int main(void)
{
    char a[51][51];
    int n, i, j;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%s",a[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = n-1; j >= 0; j--) {
            printf("%c",a[j][i]);
        }puts("");
    }
    return 0;
}

