#include <stdio.h>
#include <stdlib.h>
#define INF 1010001000
#define MAX_V 100000
#define min(a, b) a<b?a:b

typedef struct vertex {
    int edge_count;
    struct edge *head;
}vertex;

typedef struct edge {
    int to;
    struct edge *next;
}edge;

void add(int f, int t);
void dfs(int st, int prev);
void bridge(void);

vertex graph[MAX_V]; 
int used[MAX_V], prenum[MAX_V], lowest[MAX_V], parent[MAX_V], ans[MAX_V];
int from[MAX_V], dir[MAX_V];
int e, v, j;
int pre, ac;

int main(void)
{
    int i;
    scanf("%d%d", &v, &e);
    for (i = 0; i < e; i++) {
        scanf("%d %d", &from[i], &dir[i]);
        add(from[i], dir[i]);
        graph[from[i]].edge_count++;
        add(dir[i], from[i]);
        graph[dir[i]].edge_count++;
    }
    bridge();
    return 0;
}

void bridge(void)
{
    int i;
    for (i = 0; i < v; i++) {
        lowest[i] = INF;
        prenum[i] = INF;
        used[i] = 0;
    }

    pre = 1;
    dfs(0, -1);
    for (i = 0; i < v; i++) {
        if (prenum[from[i]] < lowest[dir[i]]) {
            printf("%d %d\n", from[i], dir[i]);
        }
    }
}

void dfs(int st, int prev)
{
    int cnt = 0;
    edge *tmp = graph[st].head;

    prenum[st] = pre;
    lowest[st] = pre++;
    used[st] = 1;

    while (tmp) {
        if (!used[tmp->to]) {
            cnt++;
            parent[tmp->to] = st;
            dfs(tmp->to, st);
            lowest[st] = min(lowest[st], lowest[tmp->to]);
        } else if (tmp->to != prev) {
            lowest[st] = min(lowest[st], prenum[tmp->to]);
        }
        tmp = tmp->next;
    }
    if (st == 0 && cnt > 1) {
        ans[st] = 1;
    }
}

void add(int f, int t)
{
    edge *tmp, *new_ = (edge *)malloc(sizeof(edge));
    new_->to = t;
    new_->next = NULL;
    if (graph[f].head) {
        tmp = graph[f].head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new_;
    } else {
        graph[f].head = new_;
    }
}


