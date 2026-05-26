#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>dist(n+1,INT_MAX);
    dist[n]=0;
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        int tp=q.front();
        q.pop();
        if (tp==1) break;
        for (int i=0;i<adj[tp].size();i++){
            if (dist[adj[tp][i]]==INT_MAX){
                dist[adj[tp][i]]=dist[tp]+1;
                q.push(adj[tp][i]);
            }
        }
    }
    while(!q.empty()) q.pop();
    vector<int>path;
    q.push(1);
    bool ans=false;
    while(!q.empty()){
        int tp=q.front();
        q.pop();
        path.push_back(tp);
        if (tp==n){
            ans=true;
            break;
        }
        for (int i=0;i<adj[tp].size();i++){
            if (dist[adj[tp][i]]+1==dist[tp]){
                q.push(adj[tp][i]);
                break;
            }
        }
    }
    if (!ans){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<path.size()<<"\n";
    for (int i:path) cout<<i<<" ";
    cout<<"\n";
}