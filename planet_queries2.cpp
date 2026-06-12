#include<bits/stdc++.h>
using namespace std;

int lifting[(int)2e5+1][20];
void dfs(vector<bool>&vis,vector<int>&par,vector<int>&len,int id){
    if (vis[id]) return;
    vis[id]=true;
    lifting[id][0]=par[id];
    dfs(vis,par,len,par[id]);
    len[id]=len[par[id]]+1;
    for (int i=1;i<20;i++){
        lifting[id][i]=lifting[lifting[id][i-1]][i-1];
    }
}
int jump(int a,int k){
    if (k<0) return -1;
    for (int i=0;i<20;i++){
        if (k&(1<<i)){
            a=lifting[a][i];
        }
    }
    return a;
}

int main(){
    int n,q;
    cin>>n>>q;
    vector<bool>vis(n+1,false);
    vector<int>par(n+1,0);
    vector<int>len(n+1,0);
    for (int i=1;i<=n;i++) cin>>par[i];
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            dfs(vis,par,len,i);
        }
    }
    int start;
    vector<int>ans;
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if (a==b){
            ans.push_back(0);
            continue;
        }
        start=jump(a,len[a]);
        if (jump(a,len[a]-len[b])==b)  ans.push_back(len[a]-len[b]);
        else if (jump(start,len[start]-len[b])==b) ans.push_back(len[start]-len[b]+len[a]);
        else ans.push_back(-1);
    }
    for (int i:ans) cout<<i<<"\n";
}