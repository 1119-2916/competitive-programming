#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int i, ans;
    int a[20];
    a[0] = 100;
    a[1] = 100;
    a[2] = 200;
    for(i = 3; i < 20; i++ ) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    printf("%d\n",a[19]);
    return 0;
}
