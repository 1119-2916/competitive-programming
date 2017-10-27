#include <stdio.h>
#include <stdlib.h>

#define W 21
#define H 21

typedef struct Queue{
    int q_x, q_y;
    struct Queue *next;
} Queue;

char board[W][H];
int check[W][H];
Queue *top, *bot;
int ans, wid, hei;
int dx[4] = {0, 1, 0, -1}, 
    dy[4] = {1, 0, -1, 0};

int plus_check(int a, int b);
void push(int a, int b);
Queue *pop(void);
void wfs(void);

int main(void)
{
    int i, j, x = 200, y = 200;

    scanf("%d %d",&wid, &hei);

    while (wid) {
        for (i = 0; i < hei; i++) {
            scanf("%s",board[i]);
        }

        top = NULL;
        bot = NULL;
        ans = 1;
        for (i = 0; i < hei; i++) {
            for (j = 0; j < wid; j++) {
                if (board[i][j] == '@') {
                    //printf("start : %d %d\n",i,j);
                    x = i; 
                    y = j;
                }
                check[i][j] = 0;
            }
        }
        check[x][y] = 1;
        for (i = 0; i < 4; i++) {
            if (plus_check(x+dx[i], hei) && plus_check(y+dy[i], wid)) {
                if (board[x + dx[i]][y + dy[i]] == '.') {
                    push(x + dx[i], y + dy[i]);
                    check[x + dx[i]][y + dy[i]] = 1;
                }
            }
        }
        wfs();
        printf("%d\n",ans);
        scanf("%d %d",&wid, &hei);
    }
    return 0;
}

void wfs(void) 
{
    int i;
    Queue *now;
    now = pop();
    while (now != NULL) {
        ans++;
        for (i = 0; i < 4; i++) {
            if (plus_check(now->q_x+dx[i], hei) && 
                    plus_check(now->q_y+dy[i], wid)) {
                if (board[now->q_x + dx[i]][now->q_y + dy[i]] == '.'
                        && !check[now->q_x + dx[i]][now->q_y + dy[i]] )  {
                    push(now->q_x + dx[i], now->q_y + dy[i]);
                    check[now->q_x + dx[i]][now->q_y + dy[i]] = 1;
                }
            }
        }
        now = pop();
    }
}

void push(int a, int b)
{
    Queue *new;
    //printf("%d %d\n",a, b);
    new = (Queue *)malloc(sizeof(Queue));
    new->q_x = a;
    new->q_y = b;
    new->next = NULL;
    if (bot == NULL) {
        bot = new;
        top = new;
    } else {
        top->next = new;
        top = new;
    }
}

Queue *pop(void)
{
    Queue *tmp;
    tmp = bot;
    if (bot != NULL) {
        bot = bot->next;
    }
    return tmp;
}

int plus_check(int a, int b)
{
    if (a < 0 || b <= a) {
        return 0;
    } else {
        return 1;
    }
}
