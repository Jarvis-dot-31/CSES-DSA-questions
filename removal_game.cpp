#include<bits/stdc++.h>
using namespace std;

long long dp[5000][5000];

long long helper(vector<int>&arr,int left,int right){
    if (left>right) return 0;
    if (dp[left][right]!=-1) return dp[left][right];
    long long ans=max(arr[left]-helper(arr,left+1,right),arr[right]-helper(arr,left,right-1));
    return dp[left][right]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];  
    memset(dp,-1,sizeof(dp));
    long long ans=helper(arr,0,arr.size()-1);
    for (int i:arr) ans+=(long long)i;
    cout<<ans/2<<"\n";
}