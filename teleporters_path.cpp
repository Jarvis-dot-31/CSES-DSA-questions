#include<bits/stdc++.h>
using namespace std;

// Just apply DFS and put the last result into ans like a stack or analogous to topo sort

void dfs(vector<vector<int>>&adj,vector<bool>&vis,vector<int>&ans,int id){
    if (vis[id]) return;
    vis[id]=true;
    for (int i=0;i<adj[id].size();i++){
        if (adj[id][i]==-1) continue;
        int tp=adj[id][i];
        adj[id][i]=-1;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>indeg(n+1,0);
    vector<int>outdeg(n+1,0);
    vector<vector<int>>adj(n+1);
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
        outdeg[a]++;
    }
    if (indeg[1]+1!=outdeg[1]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    if (indeg[n]!=outdeg[n]+1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for (int i=2;i<n;i++){
        if (indeg[i]!=outdeg[i]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    
}