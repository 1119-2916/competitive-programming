#include<iostream>
using namespace std;
#include<vector>

int main(){
    long long int n,a;
    cin>>n>>a;
    vector<long long int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
        x[i]-=a;
    }

       
    std::cout << "=======data=======" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << x[i] << " ";
    }
    cout << endl;
    

    //vector< vector< vector<int> > > dp(n,vector< vector<int> >(n,vector<int>(n,0)));
    vector<vector<long long int> > dp(n+1,vector<long long int>(n*n*2,0));

    dp[0][n*n]=1;

    std::cout << "========table=======" << std::endl;
    
    /*
    //for(int i=1;i<n+1;i++){
    for (int i = 0; i < n; i++) {
        //cout<<x[i]<<endl;
        for(int j=0;j<n*n*2;j++){
            //dp[i][j]=dp[i-1][j]+dp[i-1][j-x[i-1]];
            if (dp[i][j]) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j+x[i]] += dp[i][j];
            }
        }
    }
    */

    
    for(int i=1;i<n+1;i++){
        //cout<<x[i]<<endl;
        for(int j=0;j<n*n*2;j++){
            dp[i][j]=dp[i-1][j]+dp[i-1][j-x[i-1]];
            if (j - x[i-1] < 0) {
                std::cout << "warning" << std::endl;
            }
        }
    }

    
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    

    cout<<dp[n][n*n]-1<<endl;
    return 0;
}
