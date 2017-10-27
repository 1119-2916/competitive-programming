#include <stdio.h>
#include <stdlib.h>
#define MAX 2100000000

struct solve{
    int x, y;
    int num;
};

struct solve data[100000];
int yy[100000];
int l[100000];

int cmp_x(const void *a, const void *b);
int cmp_y(const void *a, const void *b);
void search(int n, int st, int en);

int main(void)
{
    int i, j, n;

    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &data[i].x, &data[i].y);
        //dp[i][0] = MAX;
        //dp[i][1] = 0;
    }

    qsort(data, n, sizeof(struct solve), cmp_x);

    j = 0;
    for (i = 0; i-1 < n; i++) {
        if (data[i].x != data[i+1].x) {
            yy[j] = data[i].y;
            j++;
        }
    }
    yy[j] = data[i+1].y;

    for (i = 0; i < j; i++) {
        l[i] = MAX;
    }

    for (i = 0; i < j; i++) {
        search(yy[i], 0, i);
    }
    for (i = 0; i < j; i++) {
        if (l[i] == MAX) {
            break;
        }
    }

    printf("%d\n",i);

    return 0;
}


int cmp_x(const void *a, const void *b) 
{
    struct solve s1 = *(struct solve *) a;
    struct solve s2 = *(struct solve *) b;

    int t1 = s1.x;
    int t2 = s2.x;
    int t3 = s1.y;
    int t4 = s2.y;
    if (t1 == t2) {
        return -(t4 - t3);
    } else {
        return t1 - t2;
    }
}

void search(int n, int st, int en) 
{
    if ((st+en)/2 == st || (st+en)/2 == en) {
        if (n == l[st]) {
            return ;
        } else if (n < l[st]) {
            l[st] = n;
        } else {
            l[en] = n;
        }
    } else if (n < l[(st+en)/2]) {
        search(n, st, (st+en)/2);
    } else {
        search(n, (st+en)/2, en);
    }
}
