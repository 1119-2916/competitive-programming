#include <stdio.h>
#include <string.h>

char input[20][128];
int n;

int main(void) {
    int i, ans = 0;
    scanf("%d",&n);
    while(n != 0) {
        for(i = 0; i < n; i++) {
            scanf("%s",input[i]);
        }
        printf("%d\n",ans);
        scanf("%d",&n);
    }
    return 0;
}

int sum(int gyo, int nowlv) {
    int ans, len, nextlv;
    len = strlen(input[gyo+1]);
    nextlv = lv(input[gyo+1]);
    if(input[gyo+1][len-1] != '+' && input[gyo+1][len-1] != '*' && 
            nowlv == nextlv) {
        return 


    
    

