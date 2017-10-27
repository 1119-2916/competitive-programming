#include <stdio.h>

int main(void) {
    int mount, m, n;
    scanf("%d%d %d",&mount, &m, &n);
    if(m == n) {
        if(m == 1) {
            if(mount % 2) {
                puts("Takahashi");
            } else {
                puts("Aoki");
            }
        } else {
            if(m >= mount) {
                puts("Takahashi");
            } else {
                if(mount % m == 1) {
                    puts("Aoki");
                } else {
                    puts("Takahashi");
                }
            }
        }
    } else {
        puts("Aoki");
    }
    return 0;
}



