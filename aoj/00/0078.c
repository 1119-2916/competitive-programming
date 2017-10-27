#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M_B 19

int board[M_B][M_B];
int n;

void print_board();
void mkbd(int x, int y, int count);
void board_clear();

int main(void) {
    scanf("%d",&n);
    while(n) {
        mkbd(n/2 +1, n/2, 1);
        print_board();
        scanf("%d",&n);
        board_clear();
    }
    return 0;
}

void print_board() {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%4d",board[i][j]);
        }
        puts("");
    }
}

void mkbd(int x, int y, int count) {
    if(count == n*n + 1) {
        return ;
    }
    if(board[x][y]) {
        x++;
        y--;
        if(x >= n) {
            x = 0;
        }
        if(y >= n) {
            y = 0;
        }
        if(y < 0) {
            y = n-1;
        }
        mkbd(x, y, count);
    } else {
        board[x][y] = count;
        if(count == n*n) {
            return ;
        }
        x++;
        y++;
        count++;
        if(x == n) {
            x = 0;
        }
        if(y == n) {
            y = 0;
        }
        mkbd(x, y, count);
    }
}

void board_clear() {
    int i, j;
    for(i = 0; i < M_B; i++) {
        for(j = 0; j < M_B; j++) {
            board[i][j] = 0;
        } 
    }
}

