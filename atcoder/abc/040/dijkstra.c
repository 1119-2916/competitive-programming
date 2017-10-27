#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define min(a, b) a<b?a:b
#define max(a, b) a>b?a:b
#define INF 1010001000
#define eps 0.000000001
#define mod 1000000007
#define MAX_NODES 200001

typedef struct edge {
    int to, cost;
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
int used[MAX_NODES];
pair queue[MAX_NODES];
int sz, V, E, start;

pair pop(void);
void push(pair x);
void add_edge(int from, int to, int cost);
void dijkstra(int st);


int main(void)
{
    int i, s, t, d, q;
    pair a;
    scanf("%d %d", &V, &E);
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &s, &t, &d);
        add_edge(s, t, d);
        add_edge(t, s, d);
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d %d", &start, &year);
        dijkstra(start, i);

    for (i = 0; i <= V; i++) {
        if (graph[i].value == INF) {
            puts("INF");
        } else {
            printf("%d\n", graph[i].value);
        }
    }
    return 0;
}


void dijkstra(int st, int pos)
{
    int i, j, v;
    pair tmp;
    edge *now;
    //Queueの初期化
    graph[st].value = 0;

    tmp.f = 0; tmp.s = st;
    push(tmp);

    ans = 0;
    while (queue[0].f != INF) {
        if (sz==0) {
            break;
        }
        tmp = pop();
        ans++;
        //printf("poped:%d %d\n", tmp.f, tmp.s);
        v = tmp.s;      //現在見ているノードの番号
        now = graph[v].head;
        if (graph[v].value < tmp.f) { 
            continue;
        }
        while (now != NULL) {
            if (graph[now->to].value > graph[v].value + now->cost) {
                graph[now->to].value = graph[v].value + now->cost;
                tmp.f = graph[now->to].value; tmp.s = now->to;
                push(tmp);
            }
            now = now->next;
        }
    }
}

void add_edge(int from, int to, int cost)
{
    //fromからtoへ辺を張る
    edge *new, *now = graph[from].head;
    new = (edge *)malloc(sizeof(edge));
    new->to = to;
    new->cost = cost;
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
    while (i > 0) {
        p = (i - 1) / 2;
        if (queue[p].f >= x.f) {
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
    //printf("sz:%d\n", sz);
    while (i * 2 + 1 < sz) {
        a = i * 2 + 1;
        b = i * 2 + 2;
        if (b < sz && queue[b].f > queue[a].f) { 
            a = b;
        }
        if (queue[a].f <= x.f) {
            break;
        }
        queue[i] = queue[a];
        i = a;
    }
    queue[i] = x;
    //queue[sz].f = INF;
    return ans;
}

