#include <stdio.h>
#include <string.h>

char input[1000][1000];

int main(void)
{
    int fl, i, j, n = 0, len, ans = 0;
    while (scanf("%s", input[n++]) != EOF);
    for (i = 0; i < n-1; i++) {
        fl = 1;
        len = strlen(input[i]);
        for (j = 0; j < len/2; j++) {
            if (len == 1) {
                break;
            }
            if (input[i][j] != input[i][len-j-1]) {
                fl = 0;
                break;
            }
        }
        if (fl) {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

