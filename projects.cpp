#include<bits/stdc++.h>
using namespace std;

int Bin(vector<vector<int>>&projs,int num,int left,int right){
    if (left>right) return right;
    int mid=(left+right)/2;
    if (projs[mid][0]>=num) return Bin(projs,num,left,mid-1);
    else return Bin(projs,num,mid+1,right);
}

long long helper(vector<long long>&dp,vector<vector<int>>&projs,int id){
    if (id<0) return 0;
    if (dp[id]!=-1) return dp[id];
    int idx=Bin(projs,projs[id][1],0,id-1);
    long long ans=max(helper(dp,projs,id-1),(long long)projs[id][2]+helper(dp,projs,idx));
    return dp[id]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>projs;
    vector<long long>dp(n,-1);
    for (int i=0;i<n;i++){
        int a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        projs.push_back({b,a,c});
    }
    sort(projs.begin(),projs.end());
    long long ans=helper(dp,projs,projs.size()-1);
    cout<<ans<<"\n";
}