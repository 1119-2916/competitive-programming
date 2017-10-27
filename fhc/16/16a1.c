#include <stdio.h>
#include <stdlib.h>

#define SIG(a) a*(a-1)/2
#define MAX_DATA 2000
#define MAX(a,b) a < b ? b : a
#define MIN(a,b) a > b ? b : a

struct pair{
    int x;
    int y;
};

struct lline{
    int a;
    int b;
    int len;
};

int data, n, l, k, i, count, j, check;
struct pair input[MAX_DATA];
struct lline line[SIG(MAX_DATA)];
int boo1, boo2;

int cmp_int(const void *a, const void *b);

int main(void) {
    scanf("%d",&data);
    for(k = 0; k < data; k++) {
        scanf("%d",&n);
        for(l = 0; l < n; l++) {
            scanf("%d %d",&input[l].x, &input[l].y);
        }
        count = 0;
        l = 0;
        for(i = 0; i < n; i++) {
            for(j = i+1; j < n; j++) {
                line[l].len = (input[i].x - input[j].x)
                    * (input[i].x - input[j].x) 
                    + (input[i].y - input[j].y)
                    * (input[i].y - input[j].y);
                line[l].a = i;
                line[l].b = j;
                l++;
            }
        }
        qsort(line, SIG(n), sizeof(struct lline), cmp_int);
        /*for(i = 0; i < SIG(n)-1; i++) {
            printf("%d %d %d\n",line[i].len, line[i].a, line[i].b);
        }*/
        for(i = 0; i < SIG(n)-1; i++) {
            for(j = i+1; j < SIG(n); j++) {
                if(line[i].len != line[j].len) {
                    break;
                }
                if(line[i].a < line[j].a
                    && line[i].a < line[j].b
                    && line[i].b < line[j].a
                    && line[i].b < line[j].b) {
                    break;
                }
                if(line[i].a == line[j].a
                        || line[i].a == line[j].b
                        || line[i].b == line[j].a
                        || line[i].b == line[j].b
                  ) {
                    count++;
                }
            }
        }
        printf("Case #%d: %d\n", k, count);
    }
    return 0;
}

int cmp_int(const void *a, const void *b) {
    struct lline tmp1 = *(struct lline *)a;
    struct lline tmp2 = *(struct lline *)b;

    int temp1 = tmp1.len;
    int temp2 = tmp2.len;
    int temp3 = tmp1.a;
    int temp4 = tmp2.a;
    int temp5 = tmp1.b;
    int temp6 = tmp2.b;

    if(temp1 == temp2) {
        if(temp3 == temp4) {
            return temp5 -temp6;
        }
        return temp3 - temp4;
    }
    return temp1 - temp2;
}

