#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    long long MOD=1e9+7;
    cin>>n;
    cin>>x;
    vector<int>coins(n);
    for (int i=0;i<n;i++) cin>>coins[i];
    vector<long>dp(x+1,0);
    dp[0]=1;
    for (int j=0;j<coins.size();j++){
        for (int i=1;i<=x;i++){
            if (i-coins[j]>=0){
                dp[i]=(dp[i]+dp[i-coins[j]])%MOD;
            }
        }
    }
    cout<<dp[x]<<"\n";
}