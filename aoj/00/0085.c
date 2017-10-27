#include <stdio.h>

int n, m;
int mem[1001];

int main(void)
{
    int i, j, count, pos;
    scanf("%d %d",&n, &m);
    while (n) {
        for (i = 0; i <= n; i++) {
            mem[i] = 0;
        }
        i = 1;
        pos = n;
        while (1) {
            pos++;
            pos = ((pos) % n) + 1;
            if (mem[pos]) {
                continue;
            }
            count++;
            if (count == m) {
                count = 0;
                mem[pos] = 1;
            }
            for (i = 0; i < n; i++) {
                if (!mem[i]) {
                    break;
                }
            }
            if (i == n) {
                printf("%d\n",pos);
                break;
            }
        }
    }
    return 0;
}

            





