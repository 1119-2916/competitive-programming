#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pair{
    int x, y;
    struct pair *next;
};

int board[51][51];
int check[51][51];
int w, h;
int ans;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

struct pair *top, *bot;

void push(int a, int b);
void bfs();
int check_board(int a, int b);

int main(void)
{
    int i, j;
    scanf("%d %d",&w, &h);
    while (w != 0 && h != 0) {
        ans = 0;
        top = NULL;
        bot = NULL;
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                scanf("%d",&board[i][j]);
                check[i][j] = 0;
            }
        }

        /*for (i = 0; i < h; i++) {
          for (j = 0; j < w; j++) {
          printf("%d",board[i][j]);
          }
          puts("");
          } */

        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                if (check[i][j] == 0 && board[i][j] == 1) {
                    check[i][j] = 1;
                    push(i, j);
                    bfs();
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
        scanf("%d %d",&w, &h);
    }
    return 0;
}

void bfs() 
{
    struct pair *now;
    int i;
    now = bot;
    while (now != NULL) {
        //printf("%d %d\n",now->x, now->y);
        for (i = 0; i < 8; i++) {
            if (check_board(now->x+dx[i], h) && 
                    check_board(now->y+dy[i], w) ) {
                if (board[now->x+dx[i]][now->y+dy[i]] == 1 && 
                        check[now->x+dx[i]][now->y+dy[i]] == 0) {
                    check[now->x+dx[i]][now->y+dy[i]] = 1;
                    push(now->x+dx[i], now->y+dy[i]);
                }
            }
        }
        now = now->next;
    }
}

void push(int a, int b)
{
    struct pair *new;
    new = (struct pair *)malloc(sizeof(struct pair));
    new->x = a;
    new->y = b;
    new->next = NULL;
    if (bot == NULL) {
        bot = new;
        top = new;
    } else {
        top->next = new;
        top = new;
    }
}

int check_board(int a, int b)
{
    if (a < 0 || b <= a) {
        return 0;
    } else {
        return 1;
    }
}

