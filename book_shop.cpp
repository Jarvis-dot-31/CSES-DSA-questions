#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    cin>>x;
    vector<int>prizes(n);
    vector<int>pages(n);
    for (int i=0;i<n;i++) cin>>prizes[i];
    for (int i=0;i<n;i++) cin>>pages[i];
    vector<int>dp(x+1,-1);
    dp[0]=0;
    for (int j=0;j<prizes.size();j++){
        for (int i=x;i>=1;i--){
            if (i-prizes[j]>=0 && dp[i-prizes[j]!=-1]){
                dp[i]=max(dp[i],pages[j]+dp[i-prizes[j]]);
            }
        }
    }
    int ans=0;
    for (int i:dp){ 
        ans=max(ans,i);
    }
    cout<<ans<<"\n";
}