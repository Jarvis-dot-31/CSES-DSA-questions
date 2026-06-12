#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&arr){
    for (int i=1;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<vector<int>>edges(m);
    vector<int>dist(n+1,INT_MAX);
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        edges[i]={a,b,c};
    }
    dist[1]=0;
    for (int i=0;i<n-1;i++){
        for (int j=0;j<m;j++){
            if (dist[edges[j][0]]!=INT_MAX && dist[edges[j][1]]>dist[edges[j][0]]+edges[j][2]){
                dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
            }
        }
        print(dist);
    }
    vector<int>ans;
    vector<bool>vis(n+1,false);
    int a=-1;
    for (int i=0;i<m;i++){
        if (dist[edges[i][0]]!=INT_MAX && dist[edges[i][1]]>dist[edges[i][0]]+edges[i][2]){
            if (a==edges[i][1]){
                ans.push_back(a);
                break;
            }
            if (a==-1) a=edges[i][0];
            dist[edges[i][1]]=dist[edges[i][0]]+edges[i][2];
            ans.push_back(edges[i][1]);
        }
    }
    if (ans.size()==0){ 
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for (int i:ans) cout<<i<<" ";
    cout<<"\n";
}