#include <stdio.h>

int c500, c100, c50, c10, c5, c1, money;
int shop[100], mark[100];

int main(void) {
    int n, i;
    scanf("%d",&n);
    while(n) {
        money = 0;
        for(i = 0; i < n; i++) {
            mark[i] = 0;
            scanf("%d",&shop[i]);
            if((1000 - (shop[i] % 1000) >= 500)) {
                mark[i] = 1;
                money += shop[i];
            }
        }
        for(i = 0; i < n; i++) {


