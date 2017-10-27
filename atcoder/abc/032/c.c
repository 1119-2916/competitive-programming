#include <stdio.h>
#define MAX_LEN 100000


int n, max, input[MAX_LEN];
int table[MAX_LEN];
long long int tmp;

int main(void) {
    int i, j;
    scanf("%d %d",&n, &max);
    for(i = 0; i < n; i++) {
        scanf("%d",&input[i]);
    }
    solve();
    max = table[0];
    for(i = 0; i < n; i++) {
        if(max < table[i]) {
            max = table[i];
        }
    }
    printf("%d\n",max);
    return 0;
}

void solve(int now, int pos) {
    if(now * input[





