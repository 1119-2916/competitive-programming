#include <stdio.h>

typedef struct item {
    int w;
    int v;
} item;

int main(void)
{
    item input[30];
    int mem_v[32800];
    int mem_w[32800];
    int i;
    for (i = 0

}

int solve(int a[], int n, int w)
{
    int tmp;
    if (n == 15) {
        tmp = 0;
    } else if (w < a[n]) {
        tmp = solve(a, n+1, w);
    } else {
        tmp = max(solve(a, n+1, w),solve(a, n+1, w - a[i].w) + a[i].v);
    }
    return tmp;
}

int max(int a, int b) 
{
    if (a < b) {
        return b;
    } else {
        return a;
    }
}

