#include <stdio.h>

int main(void) {
    int m, n ,mount;
    scanf("%d%d %d",&mount, &m, &n);
    if(mount <= m) {
        puts("Takahashi");
        return 0;
    }
    if(m == 1 && n == 1) {
        if(mount % 2) {
            puts("Takahashi");
        } else {
            puts("Aoki");
        }
        return 0;
    }
    if(m == n) {
        if(mount % m == 1) {
            if((mount / m + 1) % 2 ) {
                puts("Takahashi");
            } else {
                puts("Aoki");
            }
            return 0;
        } else {
            if((mount / m + 2) % 2 ) {
                puts("Takahashi");
            } else {
                puts("Aoki");
            }
            return 0;
        }
        return 0;
    } else if(m >= n + n) {
        puts("Takahashi");
        return 0;
    } else if(n >= m + m) {
        puts("Aoki");
        return 0;
    } else {
        if(mount % m == 1) {
            puts("Aoki");
        } else {
            puts("Takahashi");
        }
        return 0;
    }
}


