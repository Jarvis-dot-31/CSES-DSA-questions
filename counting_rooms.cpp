#include<bits/stdc++.h>
using namespace std;

void dfs(vector<string>&grid,int i,int j){
    if (i<0 || j<0 || i==grid.size() || j==grid[i].size()) return;
    if (grid[i][j]=='#') return;
    grid[i][j]='#';
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1); 
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<string>grid(n);
    int count=0;
    for (int i=0;i<n;i++) cin>>grid[i];
    for (int i=0;i<grid.size();i++){
        for (int j=0;j<grid[i].size();j++){
            if (grid[i][j]=='.'){
                count++;
                dfs(grid,i,j);
            }
        }
    }
    cout<<count<<"\n";
}