#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define min(a, b) a<b?a:b
#define max(a, b) a>b?a:b
#define INF 1010001000
#define eps 0.000000001
#define mod 1000000007
#define MAX_NODES 100001

typedef struct edge {
    int to, cost;
    struct edge *right, *left;
}edge;

typedef struct vertex{
    int value, edges;
    struct edge *head;
}vertex;

void dfs(int st, int y, int i);
void add_edge(int from, int to, int cost);
void dfs_edge(edge *pos, int y, int i);

vertex graph[MAX_NODES];
int used[MAX_NODES], ans;

int main(void)
{
    int q, n, m, i, tmpa, tmpb, tmpc;
    scanf("%d",&n);
    scanf("%d",&m);
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &tmpa, &tmpb, &tmpc);
        add_edge(tmpa, tmpb, tmpc);
        add_edge(tmpb, tmpa, tmpc);
    }
    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        ans = 0;
        scanf("%d %d", &tmpa, &tmpb);
        dfs(tmpa, tmpb, i);
        printf("%d\n", ans);
    }
    return 0;
}

void dfs(int st, int y, int i)
{
    edge *pos = graph[st].head;
    used[st] = i;
    ans++;
    dfs_edge(pos, y, i);
}

void dfs_edge(edge *pos, int y, int i)
{
    if (pos == NULL) {
        return ;
    }
    if (used[pos->to] != i && pos->cost > y) {
        dfs(pos->to, y, i);
    } else {
        dfs_edge(pos->right, y, i);
        return ;
    }
    dfs_edge(pos->left, y, i);
    dfs_edge(pos->right, y, i);
}

void add_edge(int from, int to, int cost)
{
    //fromからtoへ辺を張る
    int lr;
    edge *new, *now = graph[from].head;
    new = (edge *)malloc(sizeof(edge));
    new->to = to;
    new->cost = cost;
    new->right = NULL;
    new->left = NULL;
    if (now == NULL) {
        graph[from].head = new;
    } else {
        while (1) {
            if (now->cost < cost) {
                if (now->right) {
                    now = now->right;
                } else {
                    lr = 1;
                    break;
                }
            } else {
                if (now->left) {
                    now = now->left;
                } else {
                    lr = -1;
                    break;
                }
            }
        }
        if (lr < 0) {
            now->left = new;
        } else {
            now->right = new;
        }
    }
    graph[from].edges++;
}

