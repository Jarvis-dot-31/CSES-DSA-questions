#include<bits/stdc++.h>
using namespace std;
int d=30;
int jump(int lifting[][30],int a,int k){
    for (int i=0;i<30;i++){
        if (k&(1<<i)){
            a=lifting[a][i];
        }
    }
    return a;
}

int main(){
    int n,q;
    cin>>n>>q;
    int lifting[n+1][30];
    for (int i=1;i<=n;i++) cin>>lifting[i][0];
    for (int i=1;i<d;i++){
        for (int j=1;j<=n;j++){
            lifting[j][i]=lifting[lifting[j][i-1]][i-1];
        }
    }
    vector<int>ans;
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int c=jump(lifting,a,b);
        ans.push_back(c);
    }
    for (int i:ans) cout<<i<<"\n";
}