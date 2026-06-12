#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<ll>dist(n+1,LLONG_MAX);
    dist[1]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
    pq.push({0,1});
    pair<ll,int>tp;
    ll num,w;
    while(!pq.empty()){
        tp=pq.top();
        pq.pop();
        if (dist[tp.second]<tp.first) continue;
        for (int i=0;i<adj[tp.second].size();i++){
            num=adj[tp.second][i].first;
            w=adj[tp.second][i].second;
            if (dist[num]>dist[tp.second]+w){
                dist[num]=dist[tp.second]+w;
                pq.push({dist[num],num});
            }
        }
    }
    vector<ll>dist1(n+1,LLONG_MAX);
    priority_queue<vector<ll>,vector<vector<ll>>,greater<>>pq1;
    dist1[1]=0;
    vector<vector<ll>>cnt(n+1,{0,-1,INT_MAX});
    pq1.push({0,1,0});
    cnt[1]={1,0,0};
    vector<ll>tp1;
    while(!pq1.empty()){
        tp1=pq1.top();
        pq1.pop();
        if (dist1[tp1[1]]<tp1[0]) continue;
        for (int i=0;i<adj[tp1[1]].size();i++){
            num=adj[tp1[1]][i].first;
            w=adj[tp1[1]][i].second;
            if (dist1[num]>dist1[tp1[1]]+w){
                dist1[num]=dist1[tp1[1]]+w;
                pq1.push({dist1[num],num,tp1[2]+1});
            }
            if (dist1[tp1[1]]+w==dist1[num] && dist1[num]==dist[num]){
                cnt[num][0]=(cnt[num][0]+cnt[tp1[1]][0])%MOD;
                cnt[num][1]=max(cnt[num][1],cnt[tp1[1]][1]+1);
                cnt[num][2]=min(cnt[num][2],cnt[tp1[1]][2]+1);
            }
        }
    }
    cout<<dist1[n]<<" "<<cnt[n][0]<<" "<<cnt[n][2]<<" "<<cnt[n][1]<<"\n";
}