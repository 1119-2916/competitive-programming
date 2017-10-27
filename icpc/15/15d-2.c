#include <stdio.h>

#define MAX 5000*100
#define MAX_SHOP 100
#define MAX_DP 100001


struct dp_value {
    int mai;
    int kingaku;
};

struct dp_value dp[MAX_DP];
int shop[MAX_SHOP];
int data, five_coin, ans;

void reset_dp_array(void);
void solve(void);

int main(void)
{
    int i, j;

    scanf("%d",&data);

    while (data) {
        for (i = 0; i < data; i++) {
            scanf("%d",&shop[i]);
        }
        reset_dp_array();
        solve();
        five_coin = 0;
        for (i = 0; i < MAX_DP; i++) {
            if (five_coin < dp[i].mai) {
                five_coin = dp[i].mai;
            }
        }
        ans = MAX;
        for (i = 0; i < MAX_DP; i++) {
            if (dp[i].mai == five_coin && ans > dp[i].kingaku) {
                ans = dp[i].kingaku;
            }
        }
        printf("%d %d\n",five_coin, ans);
        scanf("%d",&data);
    }
    return 0;
}


void solve(void)
{
    int i, j, otsuri;
    for (i = 0; i < data; i++) {
        if (shop[i] % 1000) {
            otsuri = 1000 - (shop[i] % 1000);
        } else {
            otsuri = 0;
        }
        if (otsuri >= 500) {
            for (j = MAX_DP-1000; j >= 0; j--) {
                if(dp[j].kingaku != MAX) {
                    if (dp[j + otsuri].kingaku > dp[j].kingaku + shop[i]) {
                        dp[j + otsuri].kingaku = dp[j].kingaku + shop[i];
                        dp[j + otsuri].mai = dp[j].mai + 1;
                    }
                }
            }
        } else {
            for (j = MAX_DP-1000; j >= 0; j--) {
                if(dp[j].kingaku != MAX) {
                    if (j - ( dp[j].mai * 500) + otsuri >= 500) {
                        dp[j + otsuri].kingaku = dp[j].kingaku + shop[i];
                        dp[j + otsuri].mai = dp[j].mai + 1;
                    } else {
                        if (dp[j + otsuri].kingaku > dp[j].kingaku + shop[i]) {
                            dp[j + otsuri].kingaku = dp[j].kingaku + shop[i];
                        }
                    }
                }
            }
        }
    }
}


void reset_dp_array(void) 
{
    int i;
    for (i = 1; i < MAX_DP; i++) {
        dp[i].kingaku = MAX;
        dp[i].mai = 0;
    }
    dp[0].mai = 0;
    dp[0].kingaku = 0;
}

