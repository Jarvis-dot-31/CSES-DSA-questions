#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>&grid){
    for (int i=0;i<grid.size();i++){
        for (int j=0;j<grid[i].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool ans=false;
void dfs(vector<vector<int>>&grid,vector<vector<int>>&arr,int x,int y,int step){
    if (x<0 || y<0 || x>=grid.size() || y>=grid[0].size()) return;
    if (step==64){
        grid[x][y]=step;
        ans=true;
        return;
    }
    if (grid[x][y]!=INT_MAX) return; 
    if (ans) return;
    grid[x][y]=step;
    for (int i=0;i<8;i++){
        int nx=x+arr[i][0];
        int ny=y+arr[i][1];
        dfs(grid,arr,nx,ny,step+1);
    }
    grid[x][y]=INT_MAX;
}

int main(){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    vector<vector<int>>grid(8,vector<int>(8,INT_MAX));
    vector<vector<int>>arr={{1,2},{2,1},{-2,1},{2,-1},{-2,-1},{-1,2},{1,-2},{-1,-2}};
    dfs(grid,arr,y,x,1);
    print(grid);
}