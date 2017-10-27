#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_i(long long int chohen, long long int tanhen) {
    double r1, r2, r3;
    r1 = sqrt((double)chohen);
    r2 = sqrt((double)chohen-1);
    r3 = sqrt((double)tanhen);
    if(r1 == r2 + r3) {
        return 1;
    } else {
        return 0;
    }
}

int check_hen(long long int chohen, long long int tanhen) {
    double r1, r2, r3;
    r1 = sqrt((double)chohen);
    r2 = sqrt((double)tanhen);
    r3 = sqrt((double)tanhen-1);
    if(r1 == r2 + r3) {
        return 1;
    } else {
        return 0;
    }
}


int main(void) {
    long long int ans, l, i, k, hen, count = 0;
    scanf("%lld",&l);
    for(i = 2; i + i + 1 < l; i++ ) {   
        for(hen = 1; hen < i + i + 1; hen++ ) {
            if(hen == i || hen == i+1) {
                continue;
            }
            if(hen < i) {  //最長辺はi++
                count += check_i(i+1, hen);
            } else { //最長辺はhen
                count += check_hen(hen, i);
            }
        }
    }
    ans = count % 1000000007;
    printf("%lld\n",ans);
    return 0;
}
