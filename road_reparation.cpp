#include<bits/stdc++.h>
using namespace std;

int get_parent(vector<int>&parent,int id){
    if (parent[id]==id) return id;
    return parent[id]=get_parent(parent,parent[id]);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m);
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i]={c,a,b};
    }
    sort(edges.begin(),edges.end());
    vector<int>parent,rank;
    parent.push_back(-1);
    rank.push_back(-1);
    for (int i=1;i<=n;i++){
        parent.push_back(i);
        rank.push_back(1);
    }
    long long ans=0;
    for (int i=0;i<edges.size();i++){
        int u=get_parent(parent,edges[i][1]);
        int v=get_parent(parent,edges[i][2]);
        if (u==v) continue;
        else if (rank[u]>rank[v]){
            parent[v]=u;
            rank[u]+=rank[v];
        }else{
            parent[u]=v;
            rank[v]+=rank[u];
        }
        ans+=(long long)edges[i][0];
    }
    int sin=-1;
    for (int i=1;i<parent.size();i++){
        int u=get_parent(parent,i);
        if (sin==-1) sin=u;
        else if (sin!=u){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    cout<<ans<<"\n";
}