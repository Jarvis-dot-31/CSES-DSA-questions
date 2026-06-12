#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,vector<bool>&vis,stack<int>&s,int id){
    if (vis[id]) return;
    vis[id]=true;
    for (int i=0;i<adj[id].size();i++){
        dfs(adj,vis,s,adj[id][i]);
    }
    s.push(id);
}

void dfs1(vector<vector<int>>&adj,vector<bool>&vis,vector<int>&ans,int id,int king){
    if (vis[id]) return;
    vis[id]=true;
    ans[id]=king;
    for (int i=0;i<adj[id].size();i++){
        dfs1(adj,vis,ans,adj[id][i],king);
    }
}

void print(vector<vector<int>>&adj){
    for (int i=1;i<adj.size();i++){
        cout<<i<<" | ";
        for (int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<vector<int>>rev_adj(n+1);
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    // print(adj);
    // print(rev_adj);
    vector<bool>vis(n+1,false);
    stack<int>s;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            dfs(adj,vis,s,i);
        }
    }
    for (int i=0;i<vis.size();i++) vis[i]=false;
    vector<int>ans(n+1,-1);
    int ct=1;
    while(!s.empty()){
        int tp=s.top();
        s.pop();
        if (vis[tp]) continue;
        dfs1(rev_adj,vis,ans,tp,ct);
        ct++;
    }
    cout<<ct-1<<"\n";
    for (int i=1;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<"\n";
}