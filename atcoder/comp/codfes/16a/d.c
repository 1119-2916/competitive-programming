#include <stdio.h>

int board[100001][100001];

int main(void)
{
    int i, j, n, m, ans, x, y, a, count;

    scanf("%d %d", &n, &m);
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        scanf("%d %d %d", &x, &y, &a);
        board[x][y] = a;
    }

    for

