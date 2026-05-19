#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
int n,m;
long dp[1001][1<<10];

void helper(int col,int idx,int curr,int next){
    if (idx==n){
        dp[col+1][next]=(dp[col+1][next]+dp[col][curr])%MOD;
        return;
    }
    if (curr&(1<<idx)) helper(col,idx+1,curr,next);
    else{
        helper(col,idx+1,curr,next|(1<<idx));
        if (idx+1<n && !(curr&(1<<(idx+1)))){
            helper(col,idx+2,curr,next);
        }
    }
}

int main(){
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for (int i=0;i<m;i++){
        for (int mask=0;mask<(1<<n);mask++){
            if (dp[i][mask]>0){
                helper(i,0,mask,0);
            }
        }
    }
    cout<<dp[m][0]<<"\n";
}