#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,vector<bool>&vis,int id){
    if (vis[id]) return;
    vis[id]=true;
    for (int i=0;i<adj[id].size();i++){
        dfs(adj,vis,adj[id][i]);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1,false);
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>comp;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            comp.push_back(i);
            dfs(adj,vis,i);
        }
    }
    cout<<comp.size()-1<<"\n";
    for (int i=1;i<comp.size();i++){
        cout<<comp[i]<<" "<<comp[i-1]<<"\n";
    }
}