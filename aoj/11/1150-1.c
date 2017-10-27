#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 2000
#define INF 1010001000
#define min(a, b) a<b?a:b

typedef struct edge {
    int tx, ty, lr, cost;
    struct edge *next;
}edge;

typedef struct vertex {
    int edges;
    int cost;
    char value;
    struct edge *head;
}vertex;

typedef struct pair {
    int f, x, y, lr;
}pair;

vertex graph[60][30][3]; //h, w, lr
vertex clear;
pair queue[MAX_NODES];
int sz, V, E, start;
int w, h;
int dx[9] = {1, 1, 1, 1, 1, 2, 2, 2, 3};
int dy[9] = {-2, -1, 0, 1, 2, -1, 0, 1, 0};

pair pop(void);
void push(pair x);
void init(void);
void make(int w, int h);
void add_edge(int fx, int fy, int lr, int tx, int ty, char cost);
void dijkstra(int stx, int sty, int stlr);

int main(void)
{
    int i, j, k, ans;
    scanf("%d %d", &w, &h);
    while(w) {
        ans = INF;
        init();
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                scanf(" %c", &graph[i][j][0].value);
                graph[i][j][2] = graph[i][j][0];
            }
        }
        /*for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                printf("%c", graph[i][j][0].value);
            }
            puts("");
        }*/
        make(w, h);
        //puts("made");
        //printf("%d %d\n", h, w);
        for (i = 0; i < w; i++) {
            //printf("%d%c\n", i, graph[h-1][i][0].value);
            if (graph[h-1][i][0].value == 'S') {
                dijkstra(h-1, i, -1);
                for (j = 0; j < w; j++) {
                    if (graph[0][j][0].value == 'T') {
                        ans = min(ans, graph[0][j][0].cost);
                        ans = min(ans, graph[0][j][2].cost);
                    }
                }
                //printf("%d\n", ans);
                dijkstra(h-1, i, 1);
                for (j = 0; j < w; j++) {
                    if (graph[0][j][0].value == 'T') {
                        ans = min(ans, graph[0][j][0].cost);
                        ans = min(ans, graph[0][j][2].cost);
                    }
                }
                //printf("%d\n", ans);
            }
        }
        if (ans == INF) {
            puts("-1");
        } else {
            printf("%d\n", ans);
        }
        scanf("%d %d", &w, &h);
    }
    return 0;
}

void dijkstra(int stx, int sty, int stlr)
{
    int i, j, fx, fy, flr;
    //printf("Dijkstra :(%d, %d), %d\n", stx, sty, stlr);
    pair tmp;
    edge *now;
    //Queueの初期化
    for (i = 0; i < 2000; i++) {
        queue[i].f = INF;
    }
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++ ) {
            graph[i][j][0].cost = INF;
            graph[i][j][2].cost = INF;
        }
    }
    graph[stx][sty][stlr+1].cost = 0;

    tmp.f = 0; tmp.x = stx; tmp.y = sty; tmp.lr = stlr;
    push(tmp);

    while (queue[0].f != INF) {
        //puts("");
        if (sz==0) {
            break;
        }
        tmp = pop();
        //printf("poped:%d %d\n", tmp.f, tmp.s);
        fx = tmp.x;      //現在見ているノードの番号
        fy = tmp.y;
        flr = tmp.lr;
        //printf("pop:(%d, %d), %d\n", fx, fy, flr+1);
        now = graph[fx][fy][flr+1].head;
        if (graph[fx][fy][flr+1].cost < tmp.f) { 
            continue;
        }
        while (now != NULL) {
            //printf("to :(%d, %d), %d\n", now->tx, now->ty, now->lr+1);
            /*printf("cmp :(%d, %d)\n", 
                    now->cost
                    , graph[fx][fy][flr+1].cost);*/

            if (graph[now->tx][now->ty][now->lr+1].cost
                    > graph[fx][fy][flr+1].cost + now->cost) {
                graph[now->tx][now->ty][now->lr+1].cost 
                    = graph[fx][fy][flr+1].cost + now->cost;
                tmp.f = graph[now->tx][now->ty][now->lr+1].cost;
                tmp.x = now->tx;
                tmp.y = now->ty;
                tmp.lr = now->lr;
                push(tmp);
            }
            now = now->next;
        }
    }
}

void make(int w, int h)
{
    int i, j, k;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            for (k = 0; k < 9; k++) {
                if (0<=j+dx[k] && j+dx[k]<w &&
                        0<=i+dy[k] && i+dy[k]<h) {
                    add_edge(i, j, -1, i+dy[k], j+dx[k], 
                            graph[i+dy[k]][j+dx[k]][0].value);
                }
                if (0<=j-dx[k] && j-dx[k]<w &&
                        0<=i+dy[k] && i+dy[k]<h) {
                    add_edge(i, j, 1, i+dy[k], j-dx[k], 
                            graph[i+dy[k]][j-dx[k]][2].value);
                }
            }
        }
    }
}

void init(void)
{
    int i, j;
    for (i = 0; i < 60; i++) {
        for (j = 0; j < 30; j++) {
            graph[i][j][0] = clear;
            graph[i][j][2] = clear;
        }
    }
    for (i = 0; i < MAX_NODES; i++) {
        queue[i].f = 0;
    }
}

void add_edge(int fx, int fy, int lr, int tx, int ty, char cost)
{
    //fromからtoへ辺を張る
    edge *new, *now = graph[fx][fy][lr+1].head;
    new = (edge *)malloc(sizeof(edge));
    new->tx = tx;
    new->ty = ty;
    new->lr = -lr;
    if (cost == 'X') {
        return ;
    } else if (cost == 'S') {
        new->cost = 0;
    } else if (cost == 'T') {
        new->cost = 0;
    } else {
        new->cost = cost - '0';
    }
    new->next = NULL;
    if (now == NULL) {
        graph[fx][fy][lr+1].head = new;
    } else {
        while (now->next != NULL) {
            now = now->next;
        }
        now->next = new;
    }
    graph[fx][fy][lr+1].edges++;
}

void push(pair x)
{
    int i = sz++, p;
    //queue[sz++] = x;
    while (i > 0) {
        p = (i - 1) / 2;
        if (queue[p].f <= x.f) {
            break;
        }
        queue[i].f = queue[p].f;
        queue[i].x = queue[p].x;
        queue[i].y = queue[p].y;
        queue[i].lr = queue[p].lr;
        i = p;
    }
    queue[i] = x;
}

pair pop(void)
{
    int i = 0, a, b;
    pair ans = queue[0], x = queue[--sz];
    //printf("sz:%d\n", sz);
    while (i * 2 + 1 < sz) {
        a = i * 2 + 1;
        b = i * 2 + 2;
        if (b < sz && queue[b].f < queue[a].f) { 
            a = b;
        }
        if (queue[a].f >= x.f) {
            break;
        }
        queue[i] = queue[a];
        i = a;
    }
    queue[i] = x;
    //queue[sz].f = INF;
    return ans;
}
