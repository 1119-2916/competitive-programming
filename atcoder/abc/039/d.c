#include <stdio.h>

char board[105][105];
int check[101][101];
int h, w;

int solve(int i, int j);

int main(void)
{
    int i, j, k;
    scanf("%d %d", &h, &w);
    for (i = 1; i <= h; i++) {
        scanf("%s", board[i]+1);
    }
    for (i = 0; i < h+2; i++) {
        for (j = 0; j < w+2; j++) {
            if (i == 0 || i == h+1 || j == 0 || j == w+1) {
                board[i][j] = '#';
            }
        }
    }
    for (i = 1; i <= h; i++) {
        for (j = 1; j <= w; j++) {
            if (board[i][j] == '#') {
                solve(i,j);
            }
        }
    }
    for (i = 1; i <= h; i++) {
        for (j = 1; j <= w; j++) {
            if (board[i][j] == '#' && !check[i][j]) {
                puts("impossible");
                return 0;
            }
        }
    }
    puts("possible");
    for (i = 1; i <= h; i++) { 
        for (j = 1; j <= w; j++) {
            if (check[i][j] <= 1) {
                printf(".");
            } else if (check[i][j] == 2) {
                printf("#");
            }
        }
        puts("");
    }

    return 0;
}

int solve(int i, int j)
{
    int k, l;
    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (k = 0; k < 8; k++) {
        if (board[i+x[k]][j+y[k]] != '#') {
            return 0;
        }
    }
    for (k = 0; k < 8; k++) {
        if (!check[i+x[k]][j+y[k]]) {
            check[i+x[k]][j+y[k]] = 1;
        }
    }
    check[i][j] = 2;
    return 1;
}
