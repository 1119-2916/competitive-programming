#include <stdio.h>

int main(void) {
    int mount, a, b;
    scanf("%d%d %d",&mount, &a, &b);
    if(mount <= a) {
        puts("Takahashi");
    } else if(a == b) {
        if(mount % (a+1)) {
            puts("Takahashi");
        } else {
            puts("Aoki");
        }
    } else if(a < b) {
        puts("Aoki");
    } else {
        puts("Takahashi");
    }
    return 0;
}
