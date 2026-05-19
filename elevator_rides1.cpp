#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];
    vector<pair<int,int>>dp((1<<n)+1,{INT_MAX,INT_MAX});
    int mask=(1<<n);
    dp[0]={1,0};
    for (int i=1;i<=mask;i++){
        for (int j=0;j<n;j++){
            if (i&(1<<j)){
                pair<int,int>tp=dp[i^(1<<j)];
                int rides=tp.first;
                int weight=tp.second;
                if (tp.second+arr[j]>x){
                    rides++;
                    weight=arr[j];
                }else{
                    weight+=arr[j];
                }
                dp[i]=min(dp[i],{rides,weight});
            }
        }
    }
    cout<<dp[mask-1].first<<"\n";
}