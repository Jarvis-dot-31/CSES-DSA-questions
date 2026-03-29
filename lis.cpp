#include<bits/stdc++.h>
using namespace std;

int Bin(vector<int>&temp,int num,int left,int right){
    if (left>right) return left;
    int mid=(left+right)/2;
    if (temp[mid]>=num) return Bin(temp,num,left,mid-1);
    else return Bin(temp,num,mid+1,right);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];
    vector<int>temp;
    for (int i=0;i<arr.size();i++){
        int id=Bin(temp,arr[i],0,temp.size()-1);
        if (id==temp.size()) temp.push_back(arr[i]);
        else temp[id]=arr[i];
    }
    cout<<temp.size()<<"\n";
}