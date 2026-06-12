#include<bits/stdc++.h>
using namespace std;

int neg(int x,int n){
    if (x>n) return x-n;
    else return x+n; 
}

void dfs(vector<vector<int>>&adj,vector<bool>&vis,stack<int>&s,int id){
    if (vis[id]) return;
    vis[id]=true;
    for (int i=0;i<adj[id].size();i++){
        dfs(adj,vis,s,adj[id][i]);
    }
    s.push(id);
}

void dfs1(vector<vector<int>>&adj,vector<bool>&vis,vector<int>&scc,int id,int cp){
    if (vis[id]) return;
    vis[id]=true;
    scc[id]=cp;
    for (int i=0;i<adj[id].size();i++){
        dfs1(adj,vis,scc,adj[id][i],cp);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(2*(m+1)+1);
    vector<vector<int>>rev_adj(2*(m+1)+1);
    for (int j=0;j<n;j++){
        char str1,str2;
        int a,b;
        cin>>str1>>a>>str2>>b;
        if (str1=='-') a+=m;
        if (str2=='-') b+=m;
        adj[neg(a,m)].push_back(b);
        adj[neg(b,m)].push_back(a);
        rev_adj[b].push_back(neg(a,m));
        rev_adj[a].push_back(neg(b,m));
    }
    vector<bool>vis(2*(m+1)+1,false);
    stack<int>s;
    vector<int>scc(2*(m+1)+1,-1);
    for (int i=1;i<=2*(m+1);i++){
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
        dfs1(rev_adj,vis,scc,tp,ct);
        ct++;
    }
    vector<int>ans;
    for (int i=1;i<=m;i++){
        if (scc[i]>scc[neg(i,m)]) ans.push_back(1);
        else if (scc[i]<scc[neg(i,m)]) ans.push_back(-1);
        else{
            cout<<"IMPOSSIBLE\n";
            return 0;
        } 
    }
    for (int i:ans){
        if (i==1){
            cout<<'+'<<" ";
        }else{
            cout<<'-'<<" ";
        }
    }
    cout<<"\n";
}