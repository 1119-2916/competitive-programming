#include <stdio.h>
#define MAX(a, b) a < b ? b : a
#define MIN(a, b) a > b ? b : a


int main(void) {
    int a, b;
    int max, min;
    scanf("%d %d",&a, &b);
    max = MAX(a, b);
    min = MIN(a, b);
    printf("%d %d %d %d",max, MAX(a, b), min, MIN(a, b));
    return 0;
}
    
