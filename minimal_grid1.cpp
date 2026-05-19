#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) cin>>grid[i][j];
    }
    string ans="";
    queue<vector<int>>q;
    q.push({0,0,1});
    while(!q.empty()){
        vector<int>tp=q.front();
        q.pop();
        if (tp[0]==n-1 && tp[1]==n-1){ 
            ans.push_back(grid[n-1][n-1]);
            break;
        }
        if (ans.size()<tp[2]) ans.push_back(grid[tp[0]][tp[1]]);
        else{
            if (ans[tp[2]-1]>=grid[tp[0]][tp[1]]) ans[tp[2]-1]=grid[tp[0]][tp[1]];
            else continue;
        }
        char a='Z'+1;
        char b='Z'+1;
        if (tp[0]+1<n) a=grid[tp[0]+1][tp[1]];
        if (tp[1]+1<n) b=grid[tp[0]][tp[1]+1];
        if (a<b){
            q.push({tp[0]+1,tp[1],tp[2]+1});
        }else if (b<a){
            q.push({tp[0],tp[1]+1,tp[2]+1});
        }else{
            q.push({tp[0]+1,tp[1],tp[2]+1});
            q.push({tp[0],tp[1]+1,tp[2]+1});
        }
    }
    cout<<ans<<"\n";
}