#include <stdio.h>

int main(void) {
    int n, p, i, ban;
    int plr[50], wan;
    scanf("%d%d",&n, &p);
    while(n || p) {
        wan = p;
        for(i = 0; i < n; i++) {
            plr[i] = 0;
        }
        ban = 0;
        while(1) {
            if(wan) {
                plr[ban]++;
                wan--;
            } else if(plr[ban] == p) {
                break;
            } else {
                wan = plr[ban];
                plr[ban] = 0;
            }
            ban = (ban + 1) % n;
        }
        printf("%d\n",ban);
        scanf("%d%d",&n, &p);
    }
    return 0;
}



