#include <stdio.h>
#define BAN 32

char junban[24][5] = {"1234","1243","1324","1342",
    "1423","1432","2134","2143",
    "2314","2341","2413","2431",
    "3124","3142","3214","3241",
    "3412","3421","4123","4132",
    "4213","4231","4312","4321"};
int x_base[4] = { 0, 1, 0,-1};
int y_base[4] = {-1, 0, 1, 0};
int x[4];
int y[4];
int board[BAN][BAN];
int input[BAN][BAN];
int clear[2];
int ans = 1000000, ans_i, count;

void make_x_y(int n);
int find_max(void);
void board_scan(void);
int find_next(void);
void te(void);
void board_reset(void);
void te_write(void);

int main(void)
{
    int i, j;
    board_scan();

    for (i = 0; i < 24; i++) {
        count = 0;
        make_x_y(i);

        while (find_max()) {
            te();
            count++;
        }
        if (ans > count) {
            ans_i = i;
            ans = count;
        }

        board_reset();
    }
    make_x_y(ans_i);
    while (find_max()) {
        te_write();
        puts("");
    }

    return 0;
}

void te_write(void)
{
    int c0 = clear[0], c1 = clear[1];
    int tmp;

    printf("%d %d\n",c0, c1);
    board[c0][c1]--;

    tmp = find_next();
    if (tmp != -1) {
        clear[0] += x[tmp];
        clear[1] += y[tmp];
        te_write();
    }
}

void te(void)
{
    int c0 = clear[0], c1 = clear[1];
    int tmp;

    board[c0][c1]--;

    tmp = find_next();
    if (tmp != -1) {
        clear[0] += x[tmp];
        clear[1] += y[tmp];
        te();
    }
}

int find_next(void)
{
    int i, j, num = board[clear[0]][clear[1]];
    if (!num) {
        return -1;
    }
    for (i = 0; i < 4; i++) {
        if (num == board[clear[0]+x[i]][clear[1]+y[i]]) {
            return i;
        }
    }
    return -1;
}

int find_max(void)
{
    int i, j;
    int max = 0, fl = 0;
    for (i = 1; i < BAN-1; i++) {
        for (j = 1; j < BAN-1; j++) {
            if (board[i][j] > max) {
                max = board[i][j];
                fl = 1;
                clear[0] = i;
                clear[1] = j;
            }
        }
    }
    return max;
}

void board_scan(void) 
{
    int i, j;
    for (i = 0; i < BAN; i++) {
        for (j = 0; j < BAN; j++) {
            if (i != 0 && i != 31 && j != 0 && j != 31) {
                scanf("%d",&board[i][j]);
            } else {
                board[i][j] = -10;
            }
            input[i][j] = board[i][j];
        }
    }
}

void board_reset(void)
{
    int i, j;
    for (i = 0; i < BAN; i++) {
        for (j = 0; j < BAN; j++) {
            board[i][j] = input[i][j];
        }
    }
}

void make_x_y(int n) 
{
    int i;
    for (i = 0; i < 4; i++) {
        x[i] = x_base[junban[n][i]-'1'];
        y[i] = y_base[junban[n][i]-'1'];
    }
}

