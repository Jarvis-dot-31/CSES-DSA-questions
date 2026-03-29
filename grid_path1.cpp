#include<bits/stdc++.h>
using namespace std;

int main(){
    long long MOD=1e9+7;
    int n;
    cin>>n;
    vector<string>grid(n);
    for (int i=0;i<n;i++){
        cin>>grid[i];
    }
    if (grid[0][0]=='*'){
        cout<<0<<"\n";
        return 0;
    }
    vector<vector<long>>dp(n,vector<long>(n,0));
    dp[0][0]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i==0 && j==0) continue;
            if (grid[i][j]=='*') continue;
            if (i-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if (j-1>=0) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
        }
    }
    cout<<dp[n-1][n-1]<<"\n";
}