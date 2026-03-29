#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>coins(n);
    int sum=0;
    for (int i=0;i<n;i++){ 
        cin>>coins[i];
        sum+=coins[i];
    }
    vector<int>dp(sum+1,false);
    dp[0]=true;
    int ct=0;
    for (int i=0;i<coins.size();i++){
        for (int j=sum;j>0;j--){
            if (j-coins[i]>=0 && dp[j-coins[i]]){ 
                if (!dp[j]) ct++;
                dp[j]=true;
            }
        }
    }
    cout<<ct<<"\n";
    for (int i=1;i<dp.size();i++){
        if (dp[i]) cout<<i<<" ";
    }
    cout<<"\n";
}