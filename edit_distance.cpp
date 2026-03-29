#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>&dp,string &s1,string &s2,int i,int j){
    if (dp[i+1][j+1]!=INT_MAX) return dp[i+1][j+1];
    if (i<0 && j<0) return dp[i+1][j+1]=0;
    else if (i<0) return dp[i+1][j+1]=j+1;
    else if (j<0) return dp[i+1][j+1]=i+1;
    else{
        if (s1[i]==s2[j]) return helper(dp,s1,s2,i-1,j-1);
        else{
            int ans=min({1+helper(dp,s1,s2,i-1,j),1+helper(dp,s1,s2,i,j-1),1+helper(dp,s1,s2,i-1,j-1)});
            return dp[i+1][j+1]=ans;
        }
    }
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,INT_MAX));
    cout<<helper(dp,s1,s2,s1.size()-1,s2.size()-1)<<"\n";
}