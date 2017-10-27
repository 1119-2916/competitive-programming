#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char board[10];
int b_b[3][3];

void p_b(void);
void make_bb(void);
void b_c(void);
int ans(void);

int main(void) {
    int sorena;
    while(scanf("%s",board) != EOF) {
        make_bb();
        //p_b();
        sorena = ans();
        if(!sorena) {
            puts("d");
        } else if(sorena == 1) {
            puts("o");
        } else {
            puts("x");
        }
        b_c();

    }
    return 0;
}

int ans(void) {
    int i, j, flag = 0;
    int tmp;
    for(i = 0; i < 3; i++) {
        tmp = b_b[i][0];
        for(j = 1; j < 3; j++) {
            if(tmp != b_b[i][j]) {
                flag = 1;
                break;
            }
        }
        if(tmp && !flag) {
            return tmp;
        }
    }

    flag = 0;
    for(i = 0; i < 3; i++) {
        tmp = b_b[0][i];
        for(j = 1; j < 3; j++) {
            if(tmp != b_b[j][i]) {
                flag = 1;
                break;
            }
        }
        if(tmp && !flag) {
            return tmp;
        }
    }

    flag = 0;
    tmp = b_b[0][0];
    for(i = 1; i < 3; i++) {
        if(tmp != b_b[i][i]) {
            flag = 1;
            break;
        }
    }
    if(!flag && tmp) {
        return tmp;
    }

    flag = 0;
    tmp = b_b[0][2];
    for(i = 1, j = 1; i < 3; i++, j--) {
        if(tmp != b_b[i][j]) {
            flag = 1;
            break;
        }
    }
    if(!flag && tmp) {
        return tmp;
    }
    return 0;
}




void make_bb(void) {
    int i, j, k;
    for(i = 0; i < 10; i++) {
        if(board[i] == 'o') {
            b_b[i/3][i%3] = 1;
        } else if(board[i] == 'x') {
            b_b[i/3][i%3] = -1;
        }
    }
}

void p_b(void) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%3d",b_b[i][j]);
        }
        puts("");
    }
}

void b_c(void) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            b_b[i][j] = 0;
        }
    }
}

