#include <stdio.h>
#include <stdlib.h>
#define min(a, b) a<b?a:b
#define INF 1010001000
#define in(a, x) 0<=a&&a<x

char board[31][61]; //幅、高さ
int used[31][61][3];
int dy[9] = {1, 1, 1, 1, 1, 2, 2, 2, 3};
int dx[9] = {-2, -1, 0, 1, 2, -1, 0, 1, 0};
int w, h;

int dfs(int x, int y, int lr);

int main(void)
{
    int i, j, k, ans;
    scanf("%d %d", &w, &h);
    while(w) {
        ans = INF;
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                scanf(" %c", &board[i][j]);
            }
        }
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                for (k = 0; k < 3; k++) {
                    used[i][j][k] = 0;
                }
            }
        }
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                printf("%c", board[i][j]);
            }
            puts("");
        }
        for (i = 0; i < w; i++) {
            if (board[h-1][i] == 'S') {
                ans = min(ans, dfs(h-1, i, 1));
                printf("%d\n", ans);
                ans = min(ans, dfs(h-1, i, -1));
                printf("%d\n", ans);
            }
        }
        printf("%d\n", ans);
        scanf("%d %d", &w, &h);
    }
    return 0;
}
        
int dfs(int x, int y, int lr)
{
    int i, ret[9], ans = INF, fl = 0;
    used[x][y][1+lr] = 1;
    //printf("%c\n", board[x][y]);
    printf("%d %d %d\n", x, y, lr);
    for (i = 0; i < 9; i++) {
        if (board[x][y] == 'T') {
            puts("Goal");
            return 0;
        } else if (board[x][y] == 'X') {
            return INF;
        } else if (board[x][y] == 'S') {
            ret[i] = 0;
        } else {
            ret[i] = board[x][y] - '0';
        }
    }
    for (i = 0; i < 9; i++) {
        if (in(x+dx[i], h) && in(y+dy[i]*lr, w) && 
                !used[x+dx[i]][y+dy[i]*lr][1+lr*-1] &&
                board[x+dx[i]][y+dy[i]*lr] != 'X' ) {
            ret[i] += dfs(x+dx[i], y+dy[i]*lr, lr*-1);
        } else {
            ret[i] = INF;
        }
    }
    used[x][y][1+lr] = 0;
    for (i = 0; i < 9; i++) {
        ans = min(ans, ret[i]);
    }
    //printf("%d\n", ans);
    return ans;
}

