#include<bits/stdc++.h>
using namespace std;

void print(vector<long>&dp){
    for (int i:dp) cout<<i<<" ";
    cout<<"\n";
}

int main(){
    long long MOD=1e9+7;
    long long inv=500000004;
    int n;
    cin>>n;
    int sum=(n*(n+1))/2;
    if (sum%2){
        cout<<0<<"\n";
        return 0;
    }
    vector<long>dp(sum/2+1,0);
    dp[0]=1;
    for (int i=1;i<=n;i++){
        for (int j=sum/2;j>=0;j--){
            if  (j-i>=0){ 
                dp[j]=(dp[j]+dp[j-i])%MOD;
            }
        }
    }
    cout<<(dp[sum/2]*inv)%MOD<<"\n";
}