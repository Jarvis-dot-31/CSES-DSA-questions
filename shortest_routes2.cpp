#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>>dist(n+1,vector<ll>(n+1,LLONG_MAX));
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min((ll)c,dist[a][b]);
        dist[b][a]=min((ll)c,dist[b][a]);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                if (j==k){ 
                    dist[j][j]=0;
                    continue;
                }
                if (dist[j][i]!=LLONG_MAX && dist[i][k]!=LLONG_MAX){
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
    }
    vector<ll>x;
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        ll ans1=dist[a][b];
        if (ans1==LLONG_MAX) ans1=-1;
        x.push_back(ans1);
    }
    for (ll i:x) cout<<i<<"\n";
}