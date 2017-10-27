#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA 201

struct data {
    int mom;
    int hou;
};

int board[MAX_DATA][MAX_DATA];
struct data dataset[MAX_DATA];
int n;

void cl_array(void);
int cmp_data(const void *a, const void *b);


int main(void) {
    int i, j, ans;
    scanf("%d",&n);
    while(n != 0) {
        cl_array();
        for(i = 1; i < n; i++) {
            scanf("%d %d",&dataset[i].mom, &dataset[i].hou);
        }
        qsort((void *)dataset, n, sizeof(dataset[1]), cmp_data);
        /*for(i = 1; i < n; i++) {
            printf("%d, %d\n", dataset[i].mom, dataset[i].hou);
        }*/
        //puts("data end.");
        make_borad();
        scanf("%d",&n);
    }
    return 0;
}

void make_board(void) {
    int i;
    board[100][100] = 1;


int cmp_data(const void *a, const void *b) {
    struct data data1 = *(struct data *)a;
    struct data data2 = *(struct data *)b;
    int tmp1, tmp2;
    tmp1 = data1.mom;
    tmp2 = data2.mom;
    return tmp1 - tmp2;
}

void cl_array(void) {
    int i, j;
    for(i = 0; i < MAX_DATA; i++) {
        dataset[i].mom = 0;
        dataset[i].hou = 0;
        for(j = 0; j < MAX_DATA; j++) {
            board[i][j] = 0;
        }
    }
}

