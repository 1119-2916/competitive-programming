#include <stdio.h>
#include <string.h>

char rings[101][101];
char input[101];

int main(void)
{
    int i, n, len, ans = 0;
    scanf("%s%d", input, &n);
    for (i = 0; i < n; i++) {
        scanf("%s", rings[i]);
        len = strlen(rings[i]);
        strcpy(rings[i]+len, rings[i]);
        if (strstr(rings[i], input) != NULL) {
            ans++;
        }
    }
    printf("%d\n",ans);

    return 0;
}


