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
void cc(void);

vertex graph[MAX_V]; 
int used[MAX_V], prenum[MAX_V], lowest[MAX_V], parent[MAX_V], ans[MAX_V];
int e, v, j;
int pre, ac;

int main(void)
{
    int i, t, f;
    scanf("%d%d", &v, &e);
    for (i = 0; i < e; i++) {
        scanf("%d %d", &f, &t);
        add(f, t);
        graph[f].edge_count++;
        add(t, f);
        graph[t].edge_count++;
    }
    cc();
    for (i = 0; i < v; i++) {
        if (ans[i]) {
            printf("%d\n", i);
        }
    }
    return 0;
}

void cc(void)
{
    int i;
    for (i = 0; i < v; i++) {
        lowest[i] = INF;
        prenum[i] = INF;
        used[i] = 0;
        if (graph[j].edge_count < graph[i].edge_count) {
            j = i;
        }
    }

    pre = 1;
    dfs(j, -1);
    for (i = 0; i < v; i++) {
        if (i == j || parent[i] == j) {
            continue;
        }
        if (prenum[parent[i]] <= lowest[i]) {
            ans[parent[i]] = 1;
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
    if (st == j && cnt > 1) {
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

