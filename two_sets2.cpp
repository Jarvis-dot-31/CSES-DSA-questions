#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;

long long powe(long long base,long long power){
    if (power==0) return 1;
    if (power%2){
        long long a=powe(base,(power-1)/2);
        return (((a*a)%MOD)*base)%MOD;
    }else{
        long long a=powe(base,power/2);
        return (a*a)%MOD;
    }
}

int main(){
    int n;
    cin>>n;
    long long inv=powe(2,MOD-2);
    long long sum=(n*(n+1)*1ll)/2;
    if (sum%2){
        cout<<0<<"\n";
        return 0;
    }
    sum/=2;
    vector<long long>dp(sum+1,0);
    dp[0]=1;
    for (int i=1;i<=n;i++){
        for (int j=sum;j>=i;j--){
            dp[j]=(dp[j]+dp[j-i])%MOD;
        }
    }   
    cout<<(dp[sum]*inv)%MOD<<"\n";
}