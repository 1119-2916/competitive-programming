#include <stdio.h>

int t, n;
int num[10];

void init(void);
int check(void);
void write(int tmp);

int main(void)
{
    int i, j, tmp;
    scanf("%d",&t);
    for (i = 1; i <= t; i++) {
        init();
        scanf("%d",&n);
        printf("Case #%d: ", i);  //case あとで書く
        if (!n) {
            printf("INSOMNIA\n");   //no answer あとで書く
            continue;
        }
        for (j = 1; check() == 0; j++) {
            tmp = j * n;
            write(tmp);
        }
        printf("%d\n",tmp);
    }
    return 0;
}

void write(int tmp)
{
    int i, mod;
    while (tmp) {
        mod = tmp % 10;
        num[mod] = 1;
        tmp /= 10;
    }
}

void init(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        num[i] = 0;
    }
}

int check(void) 
{
    int i;
    for (i = 0; i < 10; i++) {
        if (!num[i]) {
            return 0;
        }
    }
    return 1;
}


