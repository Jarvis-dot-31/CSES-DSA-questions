#include<bits/stdc++.h>
using namespace std;

string tp;

long long dp[51][2][51];
long long helper(int id,bool tight,long long ct){
    if (id==tp.size()) return ct;
    if (dp[id][tight][ct]!=-1) return dp[id][tight][ct];
    int lim=(tight)?(tp[id]-'0'):1;
    long long ans=0;
    for (int i=0;i<=lim;i++){
        bool newtight=(tight&(i==lim));
        if (i==0) ans+=helper(id+1,newtight,ct);
        else ans+=helper(id+1,newtight,ct+1);
    }
    return dp[id][tight][ct]=ans;
}

int main(){
    long long n;
    cin>>n;
    tp="";
    while(n>0){
        if (n&1){
            tp.push_back('1');
        }else{
            tp.push_back('0');
        }
        n>>=1;
    }
    reverse(tp.begin(),tp.end());
    memset(dp,-1,sizeof(dp));
    long long ans=helper(0,true,0);
    cout<<ans<<"\n";
}