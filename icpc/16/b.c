#include <stdio.h>

int alf[26];
int n;

int main(void)
{
    int fl, i, j, ans, max, max_ind;
    char tmp[100][2];
    scanf("%d", &n);
    while (n) {
        for (j = 0; j < n; j++) {
            scanf("%s", tmp[j]);
        }
        for (i = 0; i < 26; i++) {
            alf[i] = 0;
        }
        for (i = 0; i < n; i++) {
            alf[tmp[i][0] - 'A']++;
            max = 0;
            for (j = 0; j < 26; j++) {
                if (max < alf[j]) {
                    max = alf[j];
                    max_ind = j;
                }
            }
            fl = 1;
            for (j = 0; j < 26; j++) {
                if (j != max_ind) {
                    if (alf[j] + n - i - 1>= max) {
                        fl = 0;
                        break;
                    }
                }
            }
            if (fl) {
                printf("%c %d\n", max_ind + 'A', i+1);
                break;
            }
        }
        if (i == n) {
            puts("TIE");
        }
        scanf("%d", &n);
    }
    return 0;
}



