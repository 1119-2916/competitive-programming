#include <stdio.h>
#include <stdlib.h>

struct pair {
    int pos;
    int num;
};

int n;
struct pair input[100001];

int cmpnum(const void *a, const void *b);
int cmppos(const void *a, const void *b);

int main(void)
{
    int i, j, tmp, count;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d",&input[i].num);
        input[i].pos = i;
    }
    qsort(input, n, sizeof(struct pair), cmpnum);
    i = 0;
    count = 0;
    while (i < n) {
        tmp = input[i].num;
        while (input[i].num == tmp) {
            input[i].num = count;
            i++;
        }
        count++;
    }
    qsort(input, n, sizeof(struct pair), cmppos);
    for (i = 0; i < n; i++) {
        printf("%d\n",input[i].num);
    }
    return 0;
}

int cmpnum(const void *a, const void *b)
{
    struct pair tmp1 = *(struct pair *)a;
    struct pair tmp2 = *(struct pair *)b;

    int tmp3 = tmp1.num;
    int tmp4 = tmp2.num;

    return tmp3 - tmp4;
}

int cmppos(const void *a, const void *b)
{
    struct pair tmp1 = *(struct pair *)a;
    struct pair tmp2 = *(struct pair *)b;

    int tmp3 = tmp1.pos;
    int tmp4 = tmp2.pos;

    return tmp3 - tmp4;
}


