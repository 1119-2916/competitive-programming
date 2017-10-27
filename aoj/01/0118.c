#include <stdio.h>

char board[101][101];
int check[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int h, w;

void dfs(int x, int y);

int main(void)
{
    int i, j, ans;
    scanf("%d %d", &h, &w);
    while (h) {
        for (i = 0; i < h; i++) {
            scanf("%s", board[i]);
            for (j = 0; j < w; j++) {
                check[i][j] = 0;
            }
        }
        ans = 0;
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                if (!check[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
        scanf("%d %d", &h, &w);
    }
}

void dfs(int x, int y)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (board[x][y] == board[x+dx[i]][y+dy[i]]
                && !check[x+dx[i]][y+dy[i]] 
                && 0 <= x+dx[i] && x+dx[i] < h
                && 0 <= y+dy[i] && y+dy[i] < w) {
            check[x+dx[i]][y+dy[i]] = 1;
            dfs(x+dx[i], y+dy[i]);
        }
    }
}

