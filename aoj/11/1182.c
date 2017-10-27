#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 10000
#define INF 1010001000

typedef struct edge {
    int to, cost, color;
    struct edge *next;
}edge;

typedef struct vertex {
    int value, edges;
    struct edge *head;
}vertex;

typedef struct pair {
    int f, s;
}pair;

vertex graph[MAX_NODES];
pair queue[MAX_NODES];
int mem[20][100];
int p[20], q[20][50], r[20][50];
int sz, V, E, start, goal, cl;

pair pop(void);
void push(pair x);
void add_edge(int from, int to, int cost, int color);
void dijkstra(int st, int c);
void init(void);
int calc(int line, int len);


int main(void)
{
    int i, j, s, t, d, c;
    pair a;
    scanf("%d %d %d %d %d", &V, &E, &cl, &start, &goal);
    for (i = 0; i < E; i++) {
        scanf("%d %d %d %d", &s, &t, &d, &c);
        add_edge(s, t, d, c);
        queue[i].f = INF;
    }
    for (i = 0; i < cl; i++) {
        scanf("%d", &p[i]);
    }
    for (i = 0; i < cl; i++) {
        q[i][0] = 0;
        for (j = 1; j < p[i]; j++) {
            scanf("%d", &q[i][j]);
        }
        for (j = 0; j < p[i]; j++) {
            scanf("%d", &r[i][j]);
        }
    }
/*
    for (i = 0; i < cl; i++) {
        for (j = 0; j < p[i]; j++) {
            printf("%d ", q[i][j]);
        }
        puts("");
    }
    for (i = 0; i < cl; i++) {
        for (j = 0; j < p[i]; j++) {
            printf("%d ", r[i][j]);
        }
        puts("");
    }
*/

    for (i = 1; i <= cl; i++) {
        init();
        dijkstra(start, i);
        for (j = 1; j <= V; j++) {
            printf("%d\n", graph[j].value);
            mem[i][j] = calc(i, graph[j].value);
        }
    }
    for (i = 1; i <= cl; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", mem[i][j]);
        }
        puts("");
    }
    return 0;
}

int calc(int line, int len)
{
    int ans = 0, i;
    if (len == INF) {
        return INF;
    }
    for (i = 1; i < p[line]; i++) {
        if (q[line][i] > len) {
            ans += ((len-q[line][i-1]) * r[line][i-1]);
        } else {
            ans += (q[line][i] - q[line][i-1]) * r[line][i-1];
        }
    }
    if (q[line][i] < len) {
        ans += (len - q[line][i]) * r[line][i];
    }
    return ans;
}

void init(void)
{
    int i;
    for (i = 0; i <= E; i++) {
        queue[i].f = INF;
    }
    for (i = 0; i <= V; i++) {
        graph[i].value = INF;
    }
    sz = 0;
}

void add_edge(int from, int to, int cost, int color)
{
    //fromからtoへ辺を張る
    edge *new, *now = graph[from].head;
    new = (edge *)malloc(sizeof(edge));
    new->to = to;
    new->cost = cost;
    new->color = color;
    new->next = NULL;
    if (now == NULL) {
        graph[from].head = new;
    } else {
        while (now->next != NULL) {
            now = now->next;
        }
        now->next = new;
    }
    graph[from].edges++;
}

void push(pair x)
{
    int i = sz++, p;
    //queue[sz++] = x;
    printf("pushed :%d in %d\n", x.f, x.s);
    while (i > 0) {
        p = (i - 1) / 2;
        if (queue[p].f <= x.f) {
            break;
        }
        queue[i].f = queue[p].f;
        queue[i].s = queue[p].s;
        i = p;
    }
    queue[i] = x;
}

pair pop(void)
{
    int i = 0, a, b;
    pair ans = queue[0], x = queue[--sz];
    printf("poped:%d in %d\n", ans.f, ans.s);
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

void dijkstra(int st, int c)
{
    int i, j, v;
    pair tmp;
    edge *now;
    graph[st].value = 0;

    tmp.f = 0; tmp.s = st;
    push(tmp);

    while (sz > 0) {
        if (sz == 0) {
            break;
        }
        tmp = pop();
        v = tmp.s;      //現在見ているノードの番号
        now = graph[v].head;
        if (graph[v].value < tmp.f) { 
            continue;
        }
        while (now != NULL) {
            if (now->color == c) {
                puts("1");
                printf("%d %d\n", graph[now->to].value, now->to);
                if (graph[now->to].value > graph[v].value + now->cost) {
                    graph[now->to].value = graph[v].value + now->cost;
                    tmp.f = graph[now->to].value; tmp.s = now->to;
                    //printf("pushed: %d in %d\n", tmp.f, tmp.s);
                    push(tmp);
                }
            }
            now = now->next;
        }
    }
}


