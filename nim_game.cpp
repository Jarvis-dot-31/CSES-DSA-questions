#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        int ans=0;
        for (int i=0;i<t;i++){
            int temp;
            cin>>temp;
            ans=ans^temp;
        }
        if (ans==0) cout<<"second\n";
        else cout<<"first\n";
    }
}