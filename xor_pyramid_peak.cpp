#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long ans=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (i==0 || i==n-1) ans=ans^a;
        else{
            if ((n-1)%2) ans=ans^a;
        }
    }
    cout<<ans<<"\n";
}