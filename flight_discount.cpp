#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<vector<ll>>dist(n+1,vector<ll>(2,LLONG_MAX));
    dist[1][0]=0;
    dist[1][1]=0;
    priority_queue<vector<ll>,vector<vector<ll>>,greater<>>pq;
    pq.push({0,1,0});
    vector<ll>tp;
    ll num,w;
    while (!pq.empty()){
        tp=pq.top();
        pq.pop();
        if (dist[tp[1]][tp[2]]<tp[0]) continue;
        for (int i=0;i<adj[tp[1]].size();i++){
            num=adj[tp[1]][i].first;
            w=adj[tp[1]][i].second;
            if (tp[2]==0){
                if (dist[num][0]>dist[tp[1]][0]+w){
                    dist[num][0]=dist[tp[1]][0]+w;
                    pq.push({dist[num][0],num,0});
                }
                if (dist[num][1]>dist[tp[1]][0]+w/2){
                    dist[num][1]=dist[tp[1]][0]+w/2;
                    pq.push({dist[num][1],num,1});
                }
            }else if (tp[2]==1){
                if (dist[num][1]>dist[tp[1]][1]+w){
                    dist[num][1]=dist[tp[1]][1]+w;
                    pq.push({dist[num][1],num,1});
                }
            }
        }
    }
    ll ans=min(dist[n][0],dist[n][1]);
    cout<<ans<<"\n";
}