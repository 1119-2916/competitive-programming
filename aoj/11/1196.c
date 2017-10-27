#include <stdio.h>
#include <stdlib.h>
#define INF 1010001000
#define MAX_V 1000
#define min(a, b) a<b?a:b

typedef struct edge {
    int to, cost;
    struct edge *next;
}edge;

typedef struct vertex{
    struct edge *head;
}vertex;

vertex graph[MAX_V];
int used[MAX_V], node[MAX_V][MAX_V];
int v, e, ans, all, ret;

void add(int f, int t, int c);
void init(void);
void dfs(int pos, int back);

int main(void)
{
    int i, j, tmp;
    scanf("%d", &v);
    while (v) {
        init();
        for (i = 2; i <= v; i++) {
            scanf("%d", &tmp);
            used[i] = tmp;
        }
        ret = INF;
        all = 0;
        for (i = 2; i <= v; i++) {
            scanf("%d", &tmp);
            all += tmp;
            node[i][used[i]] = tmp;
            add(i, used[i], tmp);
            node[used[i]][i] = tmp;
            add(used[i], i, tmp);
        }
        for (i = 1; i <= v; i++) {
            ans = 0;
            for (j = 1; j <= v; j++) {
                used[j] = 0;
            }
            dfs(i, 0);
            ret = min(ret, ans);
        }
        printf("%d\n", ret + all);
        scanf("%d", &v);
    }
}

void dfs(int pos, int back)
{
    edge *now = graph[pos].head;
    int flag = 0;
    used[pos] = 1;
    while (now) {
        if (!used[now->to]) {
            dfs(now->to, pos);
            flag = 1;
        }
        now = now->next;
    }
    if (flag) {
        ans += node[pos][back];
    }
}

void add(int f, int t, int c) 
{
    edge *tmp = (edge *)malloc(sizeof(edge));
    edge *pos = graph[f].head;
    tmp->to = t;
    tmp->cost = c;
    tmp->next = NULL;
    if (pos) {
        while (pos->next) {
            pos = pos->next;
        }
        pos->next = tmp;
    } else {
        graph[f].head = tmp;
    }
}

void init(void)
{
    vertex cl;
    int i, j;
    cl.head = NULL;
    for (i = 0; i < MAX_V; i++) {
        graph[i] = cl;
    }
    for (i = 0; i < MAX_V; i++) {
        for (j = 0; j < MAX_V; j++) {
            node[i][j] = 0;
        }
    }
}






