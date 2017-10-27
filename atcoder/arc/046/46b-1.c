#include <stdio.h>

int main(void) {
    int m, n, mount, count = 0;
    scanf("%d%d %d",&mount, &m, &n);
    if(m == n) {
        while(mount > m) {
            if(mount % m == 1) {
                mount -= m;
            } else if(mount % m != 0) {
                mount -= (mount % m) - 1;
            } else {
                mount -= m - 1;
            }
            count++;
        }
        count++;
        if(count % 2) {
            puts("Takahashi");
        } else {
            puts("Aoki");
        }
    } else {
        puts("Aoki");
    }
    return 0;
}

