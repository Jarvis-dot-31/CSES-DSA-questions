#include <bits/stdc++.h>
using namespace std;

bool ans=false;

void dfs(vector<vector<int>>&adj,vector<bool>&vis,vector<int>&path,unordered_set<int>&set,int id){
    if (set.find(id)!=set.end()){
        path.push_back(id);
        ans=true;
        return;
    }
    if (vis[id]) return;
    if (ans) return;
    vis[id]=true;
    path.push_back(id);
    set.insert(id);
    for (int i=0;i<adj[id].size();i++){
        if (ans) continue;
        // cout<<id<<" "<<adj[id][i]<<"\n";
        dfs(adj,vis,path,set,adj[id][i]);
    }
    set.erase(id);
    if (!ans) path.pop_back();
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    // cout<<"\n";
    vector<bool>vis(n+1,false);
    vector<int>path;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            unordered_set<int>st;
            dfs(adj,vis,path,st,i);
        }
    }
    int id=INT_MAX;
    for (int i=0;i<path.size()-1;i++){
        if (path[i]==path[path.size()-1]){
            id=i;
            break;
        }
    }
    if (id>path.size()){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout<<path.size()-id<<"\n";
    for (int i=id;i<path.size();i++) cout<<path[i]<<" ";
    cout<<"\n";
}