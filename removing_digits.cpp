#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for (int i=1;i<=n;i++){
        vector<int>digits;
        int t=i;
        while(t>0){
            digits.push_back(t%10);
            // cout<<t%10<<"\n";
            t/=10;
        }
        for (int x=0;x<digits.size();x++){
            // cout<<i<<" "<<digits[x]<<"\n";
            if (digits[x]==0) continue;
            dp[i]=min(dp[i],1+dp[i-digits[x]]);
        }
        // cout<<i<<" "<<dp[i]<<"\n";
    }
    cout<<dp[n]<<"\n";
}