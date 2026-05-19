#include<bits/stdc++.h>
using namespace std;

long long dp[20][2][2][11];
long long helper(string &a,int idx,bool tight,bool notstarted,int prev){
    if (idx==a.size()) return 1;
    if (dp[idx][tight][notstarted][prev+1]!=-1) return dp[idx][tight][notstarted][prev+1];
    int limit=(tight)?a[idx]-'0':9;
    long long ans=0;
    // cout<<idx<<" "<<tight<<" "<<prev<<" "<<notstarted<<"\n"; 
    for (int i=0;i<=limit;i++){
        if (i==prev && !notstarted) continue;
        bool newtight=(tight&(i==limit));
        bool newstarted=(notstarted&(i==0));
        ans+=helper(a,idx+1,newtight,newstarted,i);
    }
    return dp[idx][tight][notstarted][prev+1]=ans;
}

int main(){
    long long x,y;
    cin>>x>>y;
    x--;
    memset(dp,-1,sizeof(dp));
    string t=to_string(x);
    long long c=helper(t,0,true,true,-1);
    memset(dp,-1,sizeof(dp));
    t=to_string(y);
    long long d=helper(t,0,true,true,-1);
    cout<<d-c<<"\n";
}