#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>&dp){
    for (int i=0;i<dp.size();i++){
        for (int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    vector<vector<int>>dp(a,vector<int>(b,INT_MAX));
    for (int i=0;i<min(a,b);i++) dp[i][i]=0; 
    for (int i=0;i<a;i++){
        for (int j=0;j<b;j++){
            if (i==j) continue;
            for (int k=0;k<j;k++){
                // cout<<i<<" "<<j<<" "<<k<<" "<<j-k<<"\n";
                dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[i][j-k-1]);
            }
            for (int k=0;k<i;k++){
                // cout<<i<<" "<<j<<" "<<i<<" "<<i-k<<"\n";
                dp[i][j]=min(dp[i][j],1+dp[k][j]+dp[i-k-1][j]);
            }
        }
    }
    // print(dp);
    cout<<dp[a-1][b-1]<<"\n";
}