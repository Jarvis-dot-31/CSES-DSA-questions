#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>>adj(n+1);
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<multiset<ll>>dist(n+1);
    dist[1].insert(0);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
    pq.push({0,1});
    pair<ll,int>tp;
    ll num,w;
    while(!pq.empty()){
        tp=pq.top();
        pq.pop();
        if (tp.first>*dist[tp.second].rbegin()) continue;
        for (int i=0;i<adj[tp.second].size();i++){
            num=adj[tp.second][i].first;
            w=adj[tp.second][i].second;
            if (dist[num].size()<k){ 
                dist[num].insert(tp.first+w);
                pq.push({tp.first+w,num});
            }
            else{
                if (tp.first+w<*dist[num].rbegin()){  
                    auto it=dist[num].end();
                    it--;
                    dist[num].erase(it);
                    dist[num].insert(tp.first+w);
                    pq.push({tp.first+w,num});
                }
            }
        }
    }
    for (ll i:dist[n]) cout<<i<<" ";
    cout<<"\n";
}