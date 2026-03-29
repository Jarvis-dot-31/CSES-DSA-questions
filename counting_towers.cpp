#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int>a;
    long long MOD=1e9+7;
    int tp,tp1;
    while(t--){
        int n;
        cin>>n;
        vector<long>dp(2,1);
        for (int i=n-1;i>0;i--){
            tp=(2*dp[0]+dp[1])%MOD;
            tp1=(4*dp[1]+dp[0])%MOD;
            dp[0]=tp;
            dp[1]=tp1;
        }
        a.push_back((dp[0]+dp[1])%MOD);
    }
    for (int i:a) cout<<i<<"\n";
}