#include<bits/stdc++.h>
using namespace std;

bool ask(int num){
    cout<<"?"<<" "<<num<<"\n";
    string tp;
    cin>>tp;
    return tp=="YES";
}

int Bin(int left,int right){
    if (left>right) return left;
    int mid=(right-left)/2+left;
    bool tp=ask(mid);
    if (tp) return Bin(mid+1,right);
    else return Bin(left,mid-1);
}

int main(){
    int ans=Bin(1,1e9);
    cout<<"!"<<" "<<ans<<"\n";
}