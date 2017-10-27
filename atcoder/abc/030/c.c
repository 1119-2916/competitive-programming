#include <stdio.h>
#define MAX_AIR 100000
#define MAX(a, b) a < b ? b : a

int n, m, x, y, now;

int search(int a[], int now, int s, int f);

int main(void)
{
    int a[MAX_AIR], b[MAX_AIR];
    int i, j, count = 0, tmp;

    scanf("%d %d %d %d",&n, &m, &x, &y);
    for (i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%d",&b[i]);
    }

    while (now) {
        tmp = search(a, now, 0, n);
        if (tmp == n) {
            break;
        } else {
            now = a[tmp];
        }
        tmp = search(b, now, 0, m);
        if (tmp == m) {
            break;
        } else {
            now = b[tmp];
        }
        count++;
    }
    printf("%d\n",count);

    return 0;
}

int search(int a[], int now, int s, int f) 
{
    while (1) {
        if (s == f) {
            return s;
        }
        if (a[(s+f)/2] < now) {
            if (s == s+f / 2) {
                return f;
            }
            s = s+f / 2;
        } else if (a[(s+f)/2] > now) {
            f = s+f / 2;
        } else {
            return s+f/2;
        }
    }
}






