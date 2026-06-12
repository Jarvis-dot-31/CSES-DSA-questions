#include<bits/stdc++.h>
using namespace std;

int get_parent(vector<int>&parent,int id){
    if (parent[id]==id) return id;
    return parent[id]=get_parent(parent,parent[id]);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>parent,rank;
    vector<vector<int>>edges;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }
    parent.push_back(-1);
    rank.push_back(-1);
    for (int i=1;i<=n;i++){
        parent.push_back(i);
        rank.push_back(1);
    }
    int comp=n;
    int siz=1;
    for (int i=0;i<m;i++){
        int u=get_parent(parent,edges[i][0]);
        int v=get_parent(parent,edges[i][1]);
        if (u==v){ 
            cout<<comp<<" "<<siz<<"\n";
            continue;
        }
        else if (rank[u]>rank[v]){
            parent[v]=u;
            rank[u]+=rank[v];
            siz=max(siz,rank[u]);
            comp--;
        }else{
            parent[u]=v;
            rank[v]+=rank[u];
            siz=max(siz,rank[v]);
            comp--;
        }
        cout<<comp<<" "<<siz<<"\n";
    }
}