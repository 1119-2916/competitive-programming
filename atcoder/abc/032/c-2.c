#include <stdio.h>
#define MAX_INPUT 100000

int input[MAX_INPUT];
int n, max;

int main(void) {
    int i, j, si;
    long long int sum = 1;;
    scanf("%d %d",&n, &max);
    for(i = 0; i < n; i++) {
        scanf("%d",&input[i]);
        if(input[i] == 0) {
            printf("%d\n",n);
            return 0;
        }
    }
    si = 0;
    for(i = 0; i < n; i++) {
        sum *= input[i];
        while(sum <= max) {
            sum /= si;
            si++;
            if(si == i) {
                break;
            }
    


