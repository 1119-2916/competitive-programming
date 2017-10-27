#include <stdio.h>

int main(void) {
    int a, b, n, ans, i;
    scanf("%d %d %d",&a, &b, &n);
    for(i = n;; i++) {
        if(!(i % a) && !(i % b)) {
            printf("%d\n",i);
            return 0;
        }
    }
}
