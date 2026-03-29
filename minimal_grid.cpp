#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
    vector<pair<int,int>> curr;
    curr.push_back({0,0});
    string ans = "";
    ans.push_back(grid[0][0]);
    for(int step = 1; step <= 2*n-2; step++){
        vector<pair<int,int>> next;
        char best = 'Z';
        for(auto [i,j] : curr){
            if(i+1 < n){
                best = min(best, grid[i+1][j]);
            }
            if(j+1 < n){
                best = min(best, grid[i][j+1]);
            }
        }
        for(auto [i,j] : curr){
            if(i+1 < n && grid[i+1][j] == best){
                next.push_back({i+1,j});
            }
            if(j+1 < n && grid[i][j+1] == best){
                next.push_back({i,j+1});
            }
        }
        sort(next.begin(), next.end());
        next.erase(unique(next.begin(), next.end()), next.end());
        curr = next;
        ans.push_back(best);
    }
    cout << ans << "\n";
}