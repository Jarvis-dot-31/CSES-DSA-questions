#include <bits/stdc++.h>
using namespace std;

void helper(string &ans,unordered_set<string>&used,string &path,int lim,int n,int curr){
    if (ans!="") return;
    if (curr==lim){
        if (used.size()==(1<<n)) ans=path;
        return;
    }
    path.push_back('0');
    string tp=path.substr(curr-n+1,n);
    if (used.find(tp)==used.end()){ 
        used.insert(tp);
        helper(ans,used,path,lim,n,curr+1);
        used.erase(tp);
    }
    path.pop_back();
    path.push_back('1');
    tp=path.substr(curr-n+1);
    if (used.find(tp)==used.end()){
        used.insert(tp);
        helper(ans,used,path,lim,n,curr+1);
        used.erase(tp);
    }
    path.pop_back();
}

int main(){
    int n;
    cin>>n;
    int len=(1<<n)+n-1;
    string ans="";
    string path="";
    for (int i=0;i<n;i++) path.push_back('0');
    unordered_set<string>used;
    used.insert(path);
    helper(ans,used,path,len,n,n);
    cout<<ans<<"\n";
}