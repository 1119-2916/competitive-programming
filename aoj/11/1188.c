#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[10001];
int pos, n, length, vote[3335], vp;

int solve(void);
int cmp(const void *a, const void *b);

int main(void)
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", input);
        length = strlen(input);
        pos = 1;
        vp = 0;
        printf("%d\n", solve());
    }
    return 0;
}

int solve(void)
{
    int i = vp, num = 0, tmp, j, k;

    while (1) {
        if (input[pos] == '[') {
            pos++;
            vote[vp] = solve();
            vp++;
        } else if (input[pos] == ']') {
            pos++;
            if (num) {
                return num / 2 + 1;
            } else {
                qsort(vote+i, vp-i, sizeof(int), cmp);
                if ((vp-i+1)&1) {
                    for(j = i; j < (vp-i+1)/2 + i; j++) {
                        num += vote[j];
                    }
                } else {
                    for(j = i; j < (vp-i)/2+1 + i; j++) {
                        num += vote[j];
                    }
                }
                vp = i;
                return num;
            }
        } else {
            num *= 10;
            num += (input[pos] - '0');
            pos++;
        }
    }
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

