#include<bits/stdc++.h>
using namespace std;
 
void print(vector<vector<int>>&dp){
    for (int i=0;i<dp.size();i++){
        for (int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m,'0'));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) cin>>grid[i][j];
    }
    vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
    vector<vector<int>>dp1(n,vector<int>(m,INT_MAX));
    vector<vector<int>>arr={{1,0},{-1,0},{0,1},{0,-1}};
    vector<char>dirs={{'U','D','L','R'}};
    queue<pair<int,int>>q;
    int x,y;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j]=='M'){
                q.push({i,j});
                dp[i][j]=0;
            }else if (grid[i][j]=='A'){
                x=i;
                y=j;
            }
        }
    }
    pair<int,int>tp;
    while(!q.empty()){
        tp=q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int nx=tp.first+arr[i][0];
            int ny=tp.second+arr[i][1];
            if (nx<0 || ny<0 || nx==n || ny==m) continue;
            if (grid[nx][ny]=='#') continue;
            if (dp[nx][ny]>dp[tp.first][tp.second]+1){
                dp[nx][ny]=dp[tp.first][tp.second]+1;
                q.push({nx,ny});
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j]=='A'){
                dp1[i][j]=0;
                q.push({i,j});
                break;
            }
        }
    }
    while(!q.empty()){
        tp=q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int nx=tp.first+arr[i][0];
            int ny=tp.second+arr[i][1];
            if (nx<0 || ny<0 || nx==n || ny==m) continue;
            if (grid[nx][ny]=='#') continue;
            if (dp1[nx][ny]>dp1[tp.first][tp.second]+1 && dp[nx][ny]>dp1[tp.first][tp.second]+1){
                dp1[nx][ny]=dp1[tp.first][tp.second]+1;
                q.push({nx,ny});
            }
        }
    }
    int steps=INT_MAX;
    x=y=-1;
    for (int i=0;i<n;i++){
        if (dp1[i][0]<steps){
            steps=dp1[i][0];
            x=i;
            y=0;
        }
        if (dp1[i][m-1]<steps){
            steps=dp1[i][m-1];
            x=i;
            y=m-1;
        }
    }
    for (int i=0;i<m;i++){
        if (dp1[0][i]<steps){
            steps=dp1[0][i];
            x=0;
            y=i;
        }
        if (dp1[n-1][i]<steps){
            steps=dp1[n-1][i];
            x=n-1;
            y=i;
        }
    }
    if (steps==INT_MAX){
        cout<<"NO\n";
        return 0;
    }
    string path="";
    q.push({x,y});
    while(!q.empty()){
        tp=q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int nx=tp.first+arr[i][0];
            int ny=tp.second+arr[i][1];
            if (nx<0 || ny<0 || nx==n || ny==m) continue;
            if (dp1[tp.first][tp.second]==dp1[nx][ny]+1){
                path.push_back(dirs[i]);
                if (dp1[nx][ny]==0){
                    break;
                }
                q.push({nx,ny});
            }
        }
    }
    reverse(path.begin(),path.end());
    cout<<"YES\n";
    cout<<path.size()<<"\n";
    cout<<path<<"\n";
    // print(dp);
    // cout<<"\n";
    // print(dp1);
}