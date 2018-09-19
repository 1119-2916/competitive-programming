#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>

using namespace std;

#define ll long long
#define REP(i,n) for(ll (i) = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define FI first
#define SE second

ll dp[4][11111];

int main(void) {
	ll c,n,m;
	cin >> c >> n >> m;

	vector<pair<ll,ll>> v;
	
	REP(i,n){
		ll a,b;cin >> a >> b;
		v.PB(MP(a,b));
	}

	REP(i,n){
		REP(j,11110){
			dp[1][j] = max(dp[1][j],dp[0][j]);
			dp[0][j+1] = max(dp[0][j],dp[0][j+1]);


			if(j + v[i].FI < 11111){
				dp[1][j+v[i].FI] = max(dp[1][j+v[i].FI],dp[0][j]+v[i].SE);
			}
		}
		REP(j,11111){
			dp[0][j] = dp[1][j];
			dp[1][j] = 0;
		}
	}
/*
	REP(i,3){
		REP(j,50){
		cout << dp[i][j] << " ";
		}
		cout << endl;
	}

*/

	REP(i,m){
		cout << dp[0][c/(i+1)] * (i+1) << endl;
	}

	return 0;

}

