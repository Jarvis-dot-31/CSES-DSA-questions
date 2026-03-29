#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    int temp;
    for (int i=1;i<=n;i++){
        temp=i;
        int ans=INT_MAX;
        vector<int>digits;
        while(temp>0){
            digits.push_back(temp%10);
            temp/=10;
        }
        for (int j=0;j<digits.size();j++){
            if (digits[j]==0) continue;
            ans=min(ans,1+dp[i-digits[j]]);
        }
        dp[i]=ans;
    }
    cout<<dp[n]<<"\n";
}