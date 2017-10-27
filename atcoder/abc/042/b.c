#include <stdio.h>
#include <string.h>

char input[101][101], tmp[101];

int main(void)
{
    int l, n, i, j, k;

    scanf("%d %d", &n, &l);
    for (i = 0; i < n; i++) {
        scanf("%s", input[i]);
    }
    for (i = 0; i < n-1; i++) {
        for (j = n-1; j > i; j--) {
            for (k = 0; k < l; k++) {
                if (input[j][k] < input[j-1][k]) {
                    strcpy(tmp, input[j]);
                    strcpy(input[j], input[j-1]);
                    strcpy(input[j-1], tmp);
                    break;
                } else if (input[j][k] > input[j-1][k]) {
                    break;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%s", input[i]);
    }
    puts("");
    return 0;
}

