#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,vector<int>&sch,vector<bool>&vis,int id,bool &ans,unordered_set<int>&set){
    if (set.find(id)!=set.end()){
        ans=true;
        return;
    }
    if (vis[id]) return;
    set.insert(id);
    vis[id]=true;
    for (int i=0;i<adj[id].size();i++){
        dfs(adj,sch,vis,adj[id][i],ans,set);
    }
    set.erase(id);
    sch.push_back(id);
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
    vector<int>sch;
    vector<bool>vis(n+1,false);
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            bool ans=false;
            unordered_set<int>set;
            dfs(adj,sch,vis,i,ans,set);
            if (ans){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for (int i=sch.size()-1;i>=0;i--) cout<<sch[i]<<" ";
    cout<<"\n";
}