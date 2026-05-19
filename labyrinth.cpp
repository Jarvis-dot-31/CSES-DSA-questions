#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string>grid(n);
    for (int i=0;i<n;i++) cin>>grid[i];
    queue<pair<string,pair<int,int>>>q;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for (int i=0;i<grid.size();i++){
        for (int j=0;j<grid[i].size();j++){
            if (grid[i][j]=='A'){ 
                q.push({"",{i,j}});
                visited[i][j]=true;
            }
        }
    }
    vector<vector<int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
    vector<char>dir={'D','U','R','L'};
    pair<string,pair<int,int>>tp;
    bool ans=false;
    while(!q.empty() && !ans){
        tp=q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int nx=tp.second.first+dirs[i][0];
            int ny=tp.second.second+dirs[i][1];
            if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if (grid[nx][ny]=='#' || visited[nx][ny]) continue;
            tp.first.push_back(dir[i]);
            if (grid[nx][ny]=='B'){
                cout<<"YES\n";
                cout<<tp.first.size()<<"\n";
                cout<<tp.first<<"\n";
                ans=true;
            }
            visited[nx][ny]=true;
            q.push({tp.first,{nx,ny}});
            tp.first.pop_back();
        }
    }
    if (!ans) cout<<"NO\n";
}