#include <stdio.h>
#define MAX_YOKO 1001

int t, n, data, count, i, j, k;
char board[2][MAX_YOKO];

void see(int x, int y);
void see_r(int x, int y);
void see_l(int x, int y);

int main(void) {
    scanf("%d",&t);
    for(data = 1; data <= t; data++) {

        scanf("%d",&n);
        scanf("%s %s",board[0], board[1]);
        board[0][n] = 'X';
        board[1][n] = 'X';
        n++;
        count = 0;

        if(board[0][0] == '.' && board[0][1] == 'X') {
            if(board[1][0] != 'X') {
                board[1][0] = 'G';
                see(1, 0);
            } else {
                board[0][0] = 'G';
                see(0, 0);
            }
        }
           
        if(board[1][0] == '.' && board[1][1] == 'X') {
            if(board[0][0] != 'X') {
                board[0][0] = 'G';
                see(0, 0);
            } else {
                board[1][0] = 'G';
                see(1, 0);
            }
        }

        for(i = 1; i < n-1; i++) {
            if(board[0][i-1] == 'X' && 
               board[0][i] == '.' && 
               board[0][i+1] == 'X') {
                if(board[1][i] != 'X') {
                    board[1][i] = 'G';
                    see(1, i);
                } else {
                    board[0][i] = 'G';
                    see(0, i);
                }
            }
        }

        for(i = 1; i < n-1; i++) {
            if(board[1][i-1] == 'X' && 
               board[1][i] == '.' && 
               board[1][i+1] == 'X') {
                if(board[0][i] != 'X') {
                    board[0][i] = 'G';
                    see(0, i);
                } else {
                    board[1][i] = 'G';
                    see(1, i);
                }
            }
        }

        for(i = 0; i < n; i++) {
            if(board[0][i] == '.') {
                board[0][i] = 'G';
                see(0, i);
            }
        }

        for(i = 0; i < n; i++) {
            if(board[1][i] == '.') {
                board[1][i] = 'G';
                see(1, i);
            }
        }

        //printf("%s\n%s\n",board[0], board[1]);
        printf("Case #%d: %d\n",data, count);
    }
    return 0;
}


void see_l(int x, int y) {
    if(y < 0) {
        return ;
    } else if(board[x][y] == '.') {
        board[x][y] = '0';
    } else if(board[x][y] == 'X') {
        return ;
    }
    see_l(x, y-1);
}

void see_r(int x, int y) {
    if(n <= y) {
        return ;
    } else if(board[x][y] == '.') {
        board[x][y] = '0';
    } else if(board[x][y] == 'X') {
        return ;
    }
    see_r(x, y+1);
}


void see(int x, int y) {
    count++;
    see_l(x, y);
    see_r(x, y);
    if(x) {
        if(board[0][y] == '.') {
            board[0][y] = '0';
        }
    } else {
        if(board[1][y] == '.') {
            board[1][y] = '0';
        }
    }
}

