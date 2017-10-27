#include <stdio.h>
#include <string.h>

#define MAX_BD 50
#define MAX_INT_ 10000

char board[MAX_BD][MAX_BD];
int count[MAX_BD][MAX_BD];
int stx, sty, glx, gly, r, c;
int mvx[4] = {0, 1, 0, -1};
int mvy[4] = {1, 0, -1, 0};

int min(int a, int b);
int dfs(int x, int y, int tmp);

int main(void)
{
    int i, j;
    char tmp;
    scanf("%d %d",&r, &c);
    scanf("%d %d %d %d",&stx, &sty, &glx, &gly);
    for (i = 0; i < r; i++) {
        scanf("%s",board[i]);
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            count[i][j] = MAX_INT_;
        }
    }
    dfs(stx-1, sty-1, 0);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d",count[i][j]);
        }puts("");
    }
    printf("%d\n",count[glx-1][gly-1]);
    return 0;
}

int dfs(int x, int y, int tmp)
{
    int i;
    printf("%d, %d\n",x, y);
    if (board[x][y] == '.') {
        count[x][y] = min(count[x][y], tmp);
        for (i = 0; i < 4; i++) {
            dfs(x + mvx[i], y + mvy[i], tmp+1);
        }
    }
}

int min(int a, int b) 
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}





