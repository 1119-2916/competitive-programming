#include <stdio.h>

int box[100001];
int pos[100001];
int n, m;

int main(void)
{
    int i, j, x, y, count;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        box[i] = 1;
        pos[i] = 0;
    }
    pos[1] = 1;

    for (i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        if (box[x] == 1) {
            box[x] = 0;
            box[y]++;
            if (pos[y] == 0) {
                pos[y] = pos[x];
            }
            pos[x] = 0;
        } else {
            box[x]--;
            box[y]++;
            if (pos[y] == 0) {
                pos[y] = pos[x];
            }
        }
    }

    count = 0;
    for (i = 1; i <= n; i++) {
        count += pos[i];
    }

    printf("%d\n", count);

    return 0;

}
