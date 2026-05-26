#include <bits/stdc++.h>
using namespace std;

bool ans=false;

void dfs(vector<vector<int>>&adj,vector<bool>&vis,vector<int>&path,int id){
    if (vis[id]){
        // cout<<id<<"\n";
        path.push_back(id);
        ans=true;
        return;
    }
    if (ans) return;
    vis[id]=true;
    path.push_back(id);
    for (int i=0;i<adj[id].size();i++){
        if (ans) continue;
        // cout<<id<<" "<<adj[id][i]<<"\n";
        dfs(adj,vis,path,adj[id][i]);
    }
    vis[id]=false;
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
            dfs(adj,vis,path,i);
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