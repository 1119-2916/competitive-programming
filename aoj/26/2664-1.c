#include <stdio.h>
#include <string.h>
#define MAX_N 5020

int par[MAX_N], rank[MAX_N];
int price[MAX_N];
char food_name[MAX_N][11];

void init(int n);
int find(int x);
void unite(int x, int y);
int same(int x, int y);

int find_food(char name[], int n);
int min(int a, int b);


int main(void)
{
    int i, n, m, c, d, ans = 0;
    char a[11], b[11];
    scanf("%d", &n);
    init(n+1);
    for (i = 0; i < n; i++) {
        scanf("%s %d", food_name[i], &price[i]);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%s %s", a, b);
        c = find_food(a, n);
        d = find_food(b, n);
        unite(c, d);
    }
    for (i = 0; i < n; i++) {
        price[par[i]] = min(price[i], price[par[i]]);
    }
    for (i = 0; i < n; i++) {
        ans += price[par[i]];
    }
    printf("%d\n",ans);
    return 0;
}


void init(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) {
        return x;
    } else {
        par[x] = find(par[x]);
        return par[x];
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) {
        return ;
    }
    if (rank[x] < rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }
}
/*
int same(int x, int y)
{
    //同じなら0, 違うならそれ以外
    return find(x) - find(y);
}*/

int find_food(char name[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        if (!strcmp(name, food_name[i])) {
            return i;
        }
    }
    return -1;
}

int min(int a, int b)
{
    return a>b?b:a;
}
