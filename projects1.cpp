#include<bits/stdc++.h>
using namespace std;

long long Bin(vector<vector<long long>>&proj,long long time,long long left,long long right){
    if (left>right) return right;
    long long mid=(left+right)/2;
    if (proj[mid][0]<time) return Bin(proj,time,mid+1,right);
    else return Bin(proj,time,left,mid-1);
}

long long helper(vector<long long>&dp,vector<vector<long long>>&proj,long long idx){
    if (idx<0) return 0;
    if (dp[idx]!=LLONG_MAX) return dp[idx];
    long long t=Bin(proj,proj[idx][1],0,idx-1);
    // cout<<t<<" "<<idx<<"\n";
    long long ans=max(helper(dp,proj,idx-1),proj[idx][2]+helper(dp,proj,t));
    return dp[idx]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<long long>dp(n,LLONG_MAX);
    vector<vector<long long>>proj(n,vector<long long>(3,LLONG_MAX));
    for (int i=0;i<n;i++){
        cin>>proj[i][1];
        cin>>proj[i][0];
        cin>>proj[i][2];
    }
    sort(proj.begin(),proj.end());
    long long ans=helper(dp,proj,n-1);
    cout<<ans<<"\n";    
}