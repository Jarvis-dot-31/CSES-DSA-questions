#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    long long a,b,c,x;
    cin>>n>>k;
    cin>>x>>a>>b>>c;
    queue<long long>q;
    long long curr=x;
    long long ans=0;
    q.push(x);
    for (int i=1;i<n;i++){
        x=(a*x+b)%c;
        curr+=x;
        q.push(x);
        if (q.size()>k){
            curr-=q.front();
            q.pop();
        }
        if (q.size()==k) ans=ans^curr;
    }
    if (n==1){
        cout<<x<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
}