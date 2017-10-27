#include <stdio.h>
#include <string.h>

int n, count;

int main(void) {
    char sts[128];
    scanf("%d",&n);
    scanf("%s",sts);
    count = 1;
    printf("%d\n",solve(sts, 1));
    return 0;
}

int sum(char st[], int lvst) {
    char nst[128];
    int len;
    scanf("%s",nst);
    len = strlen(nst);
    if(nst[len-1] == '+') {
        sum(nst, lv(nst));
    } else if(nst[len-1] == '*') {
        kake(nst, lv(nst));
    } else if(lvst == lv(nst)) {
            return ;
        } else {
            return (st[len-1] - '0');
        }


int lv(char str[]) {
    int len;
    len = strlen(str);
    if(str[len-1] == '*' || str[len-1] == '+') {
        return len;
    } else {
        return len-1;
    }
}














    
