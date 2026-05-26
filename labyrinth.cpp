#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string>grid(n);
    int x,y;
    for (int i=0;i<n;i++) cin>>grid[i];
    queue<vector<int>>q;
    vector<vector<int>>grd(n,vector<int>(m,INT_MAX));
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for (int i=0;i<grid.size();i++){
        for (int j=0;j<grid[i].size();j++){
            if (grid[i][j]=='B'){ 
                q.push({i,j,0});
                grd[i][j]=0;
                visited[i][j]=true;
            }else if (grid[i][j]=='A'){
                x=i;
                y=j;
            }
        }
    }
    vector<vector<int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
    vector<char>dir={'D','U','R','L'};
    vector<int>tp;
    bool ans=false;
    while(!q.empty()){
        tp=q.front();
        q.pop();
        if (grid[tp[0]][tp[1]]=='A') break;
        for (int i=0;i<4;i++){
            int nx=tp[0]+dirs[i][0];
            int ny=tp[1]+dirs[i][1];
            if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if (grid[nx][ny]=='#' || visited[nx][ny]) continue;
            visited[nx][ny]=true;
            grd[nx][ny]=tp[2]+1;
            q.push({nx,ny,tp[2]+1});
        }
    }
    while(!q.empty()) q.pop();
    q.push({x,y,'O'});
    string a="";
    while(!q.empty()){
        tp=q.front();
        q.pop();
        if (tp[2]!='O') a.push_back(tp[2]);
        if (grd[tp[0]][tp[1]]==0){ 
            ans=true;
            break;
        }
        for (int i=0;i<4;i++){
            int nx=tp[0]+dirs[i][0];
            int ny=tp[1]+dirs[i][1];
            if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if (grid[nx][ny]=='#') continue;
            if (grd[nx][ny]+1!=grd[tp[0]][tp[1]]) continue;
            q.push({nx,ny,dir[i]});
            break;
        }
    }
    if (!ans){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES"<<"\n";
    cout<<a.size()<<"\n";
    cout<<a<<"\n";
}