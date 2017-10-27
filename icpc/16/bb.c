#include <stdio.h>
#include <string.h>
#define max(a, b) a>b?a:b
#define INF 1010001000

int alf[27];
char data[200][2];

int main(void)
{
    int n, i, j, tmp, pos, fl;
    scanf("%d\n", &n);
    while (n) {
        for (i = 0; i < n; i++) {
            scanf("\n%s", data[i]);
        }
        for (i = 0; i < 26; i++) {
            alf[i] = 0;
        }
        for (i = 0; i < n; i++) {
            alf[data[i][0] - 'A']++;
            tmp = 0;
            pos = 0;
            for (j = 0; j < 26; j++) {
                if (tmp < alf[j]) {
                    tmp = alf[j];
                    pos = j;
                }
            }
            fl = 0;
            for (j = 0; j < 26; j++) {
                if (j == pos) {
                    continue;
                } 
                if (alf[j] + n-i-1 >= tmp) {
                    fl = 1;
                    break;
                }
            }
            if (!fl) {
                printf("%c %d\n", pos + 'A', i+1);
                fl = 2;
                break;
            }
        }
        if (fl != 2) {
            puts("TIE");
        }
        scanf("%d", &n);
    }
    return 0;
}






