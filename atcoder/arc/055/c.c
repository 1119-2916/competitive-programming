#include <stdio.h>
#include <string.h>

char input[2001];
char a[1000], c[1000], b[2000], d[1000], e[1000];

int main(void)
{
    int n, len, i, j, k, ans = 0;
    scanf("%s", input);
    len = strlen(input);
    for (i = 1; i < len; i++) {
        for (j = 1; j < len; j++) {
            k = len - (i * 2 + j * 2);
            if (k <= 0) {
                continue;
            }
            strncpy(a, input, i);
            a[i] = '\0';
            strncpy(b, input+i, k);
            b[k] = '\0';
            strncpy(c, input+i+k,j);
            c[j] = '\0';
            strncpy(d, input+i+k+j, i);
            d[i] = '\0';
            strncpy(e, input+i+k+j+i, j);
            e[j] = '\0';
            if (!strcmp(a, d) && !strcmp(c,e)) {
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

            


