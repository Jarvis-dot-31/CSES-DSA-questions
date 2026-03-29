#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>as;
    while(n--){
        int t;
        cin>>t;
        int ans=0;
        for (int i=0;i<t;i++){
            int temp;
            cin>>temp;
            temp=temp%4;
            ans=ans^temp;
        }
        if (ans==0) as.push_back(2);
        else as.push_back(1);
    }
    for (int i=0;i<as.size();i++){
        if (as[i]==2) cout<<"second\n";
        else cout<<"first\n";
    }
}