#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA 401

struct data {
    int mom;
    int hou;
};

int board[MAX_DATA][MAX_DATA];
int mimasita[MAX_DATA][MAX_DATA];
struct data dataset[MAX_DATA];
int n, l, ans_x1, ans_y1, ans_x2, ans_y2;

void cl_array(void);
void tansaku(int num, int x, int y);
void make_board(void);
void search_ans(int x, int y);

int main(void) {
    int i, j, ans;
    scanf("%d",&n);
    while(n != 0) {
        cl_array();
        for(i = 1; i < n; i++) {
            scanf("%d %d",&dataset[i].mom, &dataset[i].hou);
        }
        make_board();
        //puts("探索終了");
        search_ans(200, 200);
        printf("%d %d\n",ans_x2-ans_x1+1, ans_y2-ans_y1+1);
        scanf("%d",&n);
    }
    return 0;
}

void make_board(void) {
    int i;
    board[200][200] = 0;
    for(i = 1; i < n; i++) {
        tansaku(i, 200, 200);
    }
}

void tansaku(int num, int x, int y) {
    if(board[x][y] == -1 || x < 0 || y < 0
            || x >= MAX_DATA || y >= MAX_DATA || mimasita[x][y] == num) {
        return;
    }
    mimasita[x][y] = num;
    if(board[x][y] != dataset[num].mom) {
        tansaku(num, x-1, y);
        tansaku(num, x, y-1);
        tansaku(num, x+1, y);
        tansaku(num, x, y+1);
    } else {
        if(dataset[num].hou == 0) {
            board[x-1][y] = num;
        } else if(dataset[num].hou == 1) {
            board[x][y+1] = num;
        } else if(dataset[num].hou == 2) {
            board[x+1][y] = num;
        } else if(dataset[num].hou == 3) {
            board[x][y-1] = num;
        }
        return;
    }
}

void cl_array(void) {
    int i, j;
    ans_x1 = 401;
    ans_x2 = -1;
    ans_y1 = 401;
    ans_y2 = -1;
    for(i = 0; i < MAX_DATA; i++) {
        for(j = 0; j < MAX_DATA; j++) {
            mimasita[i][j] = 0;
            board[i][j] = -1;
        }
    }
}

void search_ans(int x, int y) {
    int i, j;
    for(i = 0; i < MAX_DATA; i++) {
        for(j = 0; j < MAX_DATA; j++) {
            if(board[i][j] != -1) {
                if(i < ans_x1) {
                    ans_x1 = i;
                }
                if(i > ans_x2) {
                    ans_x2 = i;
                }
                if(j < ans_y1) {
                    ans_y1 = j;
                }
                if(j > ans_y2) {
                    ans_y2 = j;
                }
            }
        }
    }
}

