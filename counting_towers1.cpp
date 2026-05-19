#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;

int get_ans(int n){
    long a=1;
    long b=1;
    for (int i=2;i<=n;i++){
        long u=(4*a+b)%MOD;
        long v=(2*b+a)%MOD;
        a=u;
        b=v;
    }
    return (a+b)%MOD;
}

int main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        int a=get_ans(n);
        ans.push_back(a);
    }
    for (int i:ans) cout<<i<<"\n";
}