#include <stdio.h>
#include <stdlib.h>

struct room {
    int pos;
    int value;
};

int cmp_stc(const void *c1, const void *c2);
    
struct room input[100000];
int n;

int main(void) 
{
    int i, j, count = 1;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d",&input[i].value);
        input[i].pos = i;
    }

    qsort(input, n, sizeof(struct room), cmp_stc);

    i = 0;
    while (i < n-1) {
        if (input[i].pos > input[i+1].pos) {
            count++;
        }
        i++;
    }
    if (input[i].pos == 0 && count != 1) {
        count--;
    }
    printf("%d\n",count);
    return 0;
}

int cmp_stc(const void *c1, const void *c2)
{
    struct room a1 = *(struct room *)c1;
    struct room a2 = *(struct room *)c2;

    struct room a3 = *(struct room *)c1;
    struct room a4 = *(struct room *)c2;

    int tmp1 = a1.value;
    int tmp2 = a2.value;

    int tmp3 = a1.pos;
    int tmp4 = a2.pos;

    if (tmp1 == tmp2) {
        return tmp3 - tmp4;
    }
    return tmp1 - tmp2;
}
    



