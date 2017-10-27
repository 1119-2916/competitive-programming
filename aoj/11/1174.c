#include <stdio.h>
#define max(a, b) a<b?b:a
#define INF 1010001000

int board[10][10];
int copy[10][10];
int used[10][10];
int h, w, c, ans, ret;

void init(void);
void clused(void);
void dfs(int color, int x, int y);
void count(int color, int x, int y);

int main(void)
{
    int i, j, k, l, m, n;
    scanf("%d%d%d", &h, &w, &c);
    while (h) {
        init();
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                scanf("%d", &board[i][j]);
                board[i][j]--;
                copy[i][j] = board[i][j];
            }
        }
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                for (k = 0; k < 6; k++) {
                    for (l = 0; l < 6; l++) {
                        for (n = 0; n <= h; n++) {
                            for (m = 0; m <= w; m++) {
                                board[n][m] = copy[n][m];
                            }
                        }
                        dfs(i, 0, 0);
                        clused();

                        dfs(j, 0, 0);
                        clused();

                        dfs(k, 0, 0);
                        clused();

                        dfs(l, 0, 0);
                        clused();

                        dfs(c-1, 0, 0);
                        clused();

                        ans = 0;
                        count(c-1, 0, 0);
                        clused();

                        ret = max(ret, ans);
                    }
                }
            }
        }
        printf("%d\n", ret);
        scanf("%d%d%d", &h, &w, &c);
    }
    return 0;
}

void count(int color, int x, int y) 
{
    int i;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    ans++;
    used[x][y] = 1;
    for (i = 0; i < 4; i++) {
        if (0 <= x + dx[i]  && x + dx[i] < h && 
                0 <= dy[i] + y && dy[i] + y < w &&
                !used[x+dx[i]][y+dy[i]] && 
                board[x+dx[i]][y+dy[i]] == board[x][y]) {
            count(color, x+dx[i], y+dy[i]);
        }
    }
}

void dfs(int color, int x, int y)
{
    int i;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    used[x][y] = 1;
    for (i = 0; i < 4; i++) {
        if (0 <= x + dx[i]  && x + dx[i] < h && 
                0 <= dy[i] + y && dy[i] + y < w &&
                !used[x+dx[i]][y+dy[i]] && 
                board[x+dx[i]][y+dy[i]] == board[x][y]) {
            dfs(color, x+dx[i], y+dy[i]);
        }
    }
    board[x][y] = color;
}

void init(void)
{
    int i, j;
    for (i = 0; i <= h; i++) {
        for (j = 0; j <= w; j++) {
            board[i][j] = INF;
            used[i][j] = 0;
        }
    }
    ret = 0;
    ans = 0;
}

void clused(void)
{
    int i, j;
    for (i = 0; i <= h; i++) {
        for (j = 0; j <= w; j++) {
            used[i][j] = 0;
        }
    }
}
