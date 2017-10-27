#include <stdio.h>
#include <string.h>
#define MAX_N 5020

int par[MAX_N];
int price[MAX_N];
char food_name[MAX_N][MAX_N];

void init(int n);
int find(int x);
void unite(int x, int y);
int same(int x, int y);
int min(int a, int b);

void init(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        par[i] = i;
        price[i] = 0;
    }
}

int find(int x)
{
    int tmp;
    if (par[x] == x) {
        return x;
    } else {
        tmp = find(par[x]);
        par[x] = tmp;
        price[x] = min(price[x], price[tmp]);
        price[tmp] = min(price[x], price[x]);
        return tmp;
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) {
        return ;
    }
    if (price[x] < price[y]) {
        par[x] = y;
        price[y] = price[x];
    } else {
        par[y] = x;
        price[x] = price[y];
    }
}

int same(int x, int y)
{
    //同じなら0, 違うならそれ以外
    return find(x) - find(y);
}

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
    return a<b?a:b;
}

int main(void)
{
    int i, n, m, c, d, ans = 0;
    char a[11], b[11];
    scanf("%d", &n);
    init(n);
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
        printf("%d\n",price[i]);
        ans += price[i];
    }
    printf("%d\n",ans);
    return 0;
}

