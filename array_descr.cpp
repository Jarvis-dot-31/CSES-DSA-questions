#include<bits/stdc++.h>
using namespace std;
 
const long long MOD=1e9+7;
 
int process(vector<vector<long>>&dp,vector<int>&arr,int id,int prev,int m){
    if (id>=arr.size() || arr[id]!=0) return 1;
    if (prev==-1 && dp[id][prev+1]!=INT_MAX) return dp[id][prev+1]%MOD;
    else if (prev!=-1 && dp[id][prev]!=INT_MAX) return dp[id][prev]%MOD;
    int ans=0;
    int next=(id+1>=arr.size() || arr[id+1]==0)?-1:arr[id+1];
    if (prev==-1){
        if (next==-1){
            for (int i=1;i<=m;i++){
                ans=(ans+process(dp,arr,id+1,i,m))%MOD;
            }
        }else{
            for (int i=max(1,next-1);i<=min(m,next+1);i++){
                ans=(ans+process(dp,arr,id+1,i,m))%MOD;
            }
        }
    }else{
        if (next==-1){
            for (int i=max(1,prev-1);i<=min(m,prev+1);i++){
                ans=(ans+process(dp,arr,id+1,i,m))%MOD;
            }
        }else{
            if (abs(prev-next)==1){
                ans=(ans+process(dp,arr,id+1,prev,m))%MOD;
                ans=(ans+process(dp,arr,id+1,next,m))%MOD;
            }else if (prev==next){
                for (int i=max(1,prev-1);i<=min(m,prev+1);i++){
                    ans=(ans+process(dp,arr,id+1,i,m))%MOD;
                }
            }else if (abs(prev-next)==2){
                ans=(ans+process(dp,arr,id+1,(prev+next)/2,m))%MOD;
            }
        }
    }
    if (prev==-1) dp[id][prev+1]=ans%MOD;
    else dp[id][prev]=ans%MOD;
    return ans%MOD;
}
 
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<int>arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];
    vector<long>ans;
    vector<vector<long>>dp(n,vector<long>(m+1,INT_MAX));
    int i=0;
    int a;
    while(i<arr.size()){
        if (arr[i]==0){
            if (i==0){
                a=process(dp,arr,i,-1,m);
            }else{
                a=process(dp,arr,i,arr[i-1],m);
            }
            while(i<arr.size() && arr[i]==0) i++;
            ans.push_back(a);
        }else{
            while(i<arr.size() && arr[i]!=0){
                if (i-1>=0 && arr[i-1]>0 && abs(arr[i]-arr[i-1])>1){
                    cout<<0<<"\n";
                    return 0;
                }
                i++;
            }
        }
    }
    long t=1;
    for (long i:ans){
        t=(t*i)%MOD;
    }
    cout<<t<<"\n";
}