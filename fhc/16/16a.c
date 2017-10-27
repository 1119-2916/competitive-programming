#include <stdio.h>

struct pair{
    int x;
    int y;
};

int data, n, l, k, i, count, j;
struct pair input[2000];
int boo1, boo2;

int main(void) {
    scanf("%d",&data);
    for(k = 0; k < data; k++) {
        scanf("%d",&n);
        for(l = 0; l < n; l++) {
            scanf("%d %d",&input[l].x, &input[l].y);
        }
        count = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                for(l = j; l < n; l++) {
                    if(j == l || i == l) {
                        continue;
                    }
                    boo1 = (input[i].x - input[j].x)
                        * (input[i].x - input[j].x) 
                        + (input[i].y - input[j].y)
                        * (input[i].y - input[j].y);
                    boo2 = (input[i].x - input[l].x)
                        * (input[i].x - input[l].x) 
                        + (input[i].y - input[l].y)
                        * (input[i].y - input[l].y);
                    if(boo1 == boo2) {
                        //printf("%d %d\n", boo1, boo2);
                        count++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",k, count/2);
    }
    return 0;
}






