#include <stdio.h>

char board[13][13];
//int check[12][12];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int ans;

void dfs(int x, int y);

int main(void)
{
    int i, j;
    while (scanf("%s", board[0]) != EOF) {
        for (i = 1; i < 12; i++) {
            scanf("%s", board[i]);
        }
        ans = 0;
        /*for (i = 0; i < 12; i++) {
            for (j = 0; j < 12; j++) {
                board[i][j] -= '0';
            }
        }
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 12; j++) {
                printf("%d", (int)board[i][j]);
            }
            puts("");
        }*/
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 12; j++) {
                if (board[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

void dfs(int x, int y)
{
    int i;
    board[x][y] = '0';
    for (i = 0; i < 4; i++) {
        if (0 <= x+dx[i] && x+dx[i] < 12
                && 0 <= y+dy[i] && y+dy[i] < 12) {
            if(board[x+dx[i]][y+dy[i]] == '1') {
                dfs(x+dx[i], y+dy[i]);
            }
        }
    }
}

