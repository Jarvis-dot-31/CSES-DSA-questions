#include<bits/stdc++.h>
using namespace std;

unordered_map<int,long long>scc_coin;

void dfs(vector<vector<int>>&adj,vector<bool>&vis,stack<int>&s,int id){
    if (vis[id]) return;
    vis[id]=true;
    for (int i=0;i<adj[id].size();i++){
        dfs(adj,vis,s,adj[id][i]);
    }
    s.push(id);
}

void dfs1(vector<vector<int>>&adj,vector<int>&coins,vector<int>&scc,vector<bool>&vis,int id,int cp,long long &sum){
    if (vis[id]) return;
    vis[id]=true;
    scc[id]=cp;
    sum+=(long long)coins[id-1];
    for (int i=0;i<adj[id].size();i++){
        dfs1(adj,coins,scc,vis,adj[id][i],cp,sum);
    }
}
void dfs2(unordered_map<int,vector<int>>&scc_adj,vector<vector<int>>&adj,vector<bool>&vis,int id,vector<int>&scc,int par_scc){
    if (scc[id]!=par_scc) scc_adj[par_scc].push_back(scc[id]);
    if (vis[id]) return;
    vis[id]=true;
    for (int i=0;i<adj[id].size();i++){
        dfs2(scc_adj,adj,vis,adj[id][i],scc,scc[id]);
    }

}
long long helper(vector<long long>&dp,unordered_map<int,vector<int>>&scc_adj,int id){
    if (dp[id]!=LLONG_MAX) return dp[id];
    long long ans=0;
    for (int i=0;i<scc_adj[id].size();i++){
        ans=max(ans,helper(dp,scc_adj,scc_adj[id][i]));
    }
    return dp[id]=ans+scc_coin[id];
}
void print(unordered_map<int,vector<int>>&scc_coin){
    for (auto it=scc_coin.begin();it!=scc_coin.end();it++){
        cout<<it->first<<" | ";
        for (int i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>coins(n);
    for (int i=0;i<n;i++) cin>>coins[i];
    vector<vector<int>>adj(n+1);
    vector<vector<int>>rev_adj(n+1);
    unordered_map<int,vector<int>>scc_adj;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    vector<bool>vis(n+1,false);
    vector<int>scc(n+1,-1);
    stack<int>s;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            dfs(adj,vis,s,i);
        }
    }
    for (int i=0;i<vis.size();i++) vis[i]=false;
    int ct=1;
    while(!s.empty()){
        int tp=s.top();
        s.pop();
        if (vis[tp]) continue;
        long long sum=0;
        dfs1(rev_adj,coins,scc,vis,tp,ct,sum);
        scc_coin[ct]=sum;
        ct++;
    }
    for (int i=0;i<vis.size();i++) vis[i]=false;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            dfs2(scc_adj,adj,vis,i,scc,scc[i]);
        }
    }
    vector<long long>dp(n+1,LLONG_MAX);
    long long ans=0;
    for (int i=1;i<=n;i++){
        ans=max(ans,helper(dp,scc_adj,i));
    }
    cout<<ans<<"\n";
    // print(scc_adj);
}