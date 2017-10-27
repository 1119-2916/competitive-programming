#include <stdio.h>

#define MAX 5000*100
#define MAX_SHOP 100
#define MAX_DP 49900

struct pair {
    int price;
    int mai;
};

struct pair dp[MAX_DP];
int shop[MAX_SHOP];
int data;

void reset_dp_array(void);
void solve(void);

int main(void) 
{
    int i, j, five_coin, ans;

    scanf("%d",&data);

    while (data) {
        for (i = 0; i < data; i++) {
            scanf("%d",&shop[i]);
        }
        reset_dp_array();
        solve();
        for (i = MAX_DP-1; i >= 0; i--) {
            if (dp[i].price != MAX) {
                break ;
            }
        }

        for (j = 0; j < MAX_DP; j++) {
            if (dp[j].price != MAX) {
                printf("%d %d\n",dp[j].price, dp[j].mai);
            }
        }

        five_coin = i / 500;
        ans = dp[i].price;
        for (j = five_coin * 500; j < (five_coin * 500) + 500; j++) {
            if (ans > dp[j].price) {
                ans = dp[j].price;
            }
        }
        printf("%d %d\n",five_coin, ans);
        scanf("%d",&data);
    }
    return 0;
}

void reset_dp_array(void) 
{
    int i;
    for (i = 1; i < MAX_DP; i++) {
        dp[i].price = MAX;
        dp[i].mai = 0;
    }
    dp[0].price = 0;
    dp[0].mai = 0;
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
        for (j = MAX_DP-1000; j >= 0; j--) {
            if (otsuri >= 500) { 
                if (dp[j].price != MAX) {
                    if (dp[j + otsuri].price > dp[j].price + shop[i]) {
                        dp[j + otsuri].price = dp[j].price + shop[i];
                        dp[j + otsuri].mai = dp[j].mai + 1;
                    } 
                } 
            } else {
                if (dp[j].price != MAX) {
                    if (dp[j + otsuri].price > dp[j].price + shop[i]) {
                        dp[j + otsuri].price = dp[j].price + shop[i];
                        dp[j + otsuri].mai = dp[j].mai;
                    }
                }
            }
        }
    }
}


