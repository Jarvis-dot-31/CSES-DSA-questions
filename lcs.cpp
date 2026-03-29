#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<int>arr1(n);
    vector<int>arr2(m);
    for (int i=0;i<n;i++) cin>>arr1[i];
    for (int i=0;i<m;i++) cin>>arr2[i];
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i=n-1;i>=0;i--){
        for (int j=m-1;j>=0;j--){
            if (arr1[i]==arr2[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    vector<int>seq;
    int ct=dp[0][0];
    for (int i=0;i<dp.size()-1;i++){
        for (int j=0;j<dp[i].size()-1;j++){
            if (arr1[i]==arr2[j] && dp[i][j]==ct){
                seq.push_back(arr1[i]);
                ct--;
                break;
            }
        }
    }
    cout<<dp[0][0]<<"\n";
    for (int i:seq) cout<<i<<" ";
    cout<<"\n";
}