#include<bits/stdc++.h>
using namespace std;

long long helper(vector<vector<long long>>&dp,vector<int>&arr,int i,int j){
    if (i==j) return arr[i];
    else if (i>j) return 0;
    if (dp[i][j]!=LONG_MIN) return dp[i][j];
    long long ans;
    ans=max(arr[i]-helper(dp,arr,i+1,j),arr[j]-helper(dp,arr,i,j-1));
    // cout<<arr[i]<<" "<<arr[j]<<" "<<val<<" "<<val1<<" "<<val2<<" "<<ans<<"\n";
    return dp[i][j]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];
    vector<vector<long long>>dp(n,vector<long long>(n,LONG_MIN));
    long long diff=helper(dp,arr,0,arr.size()-1);
    for (int i:arr) diff+=(long long)i;
    cout<<diff/2<<"\n";
}