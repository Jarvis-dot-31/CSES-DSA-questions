#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    vector<pair<int,int>> dp(1<<n, {n+1, 0});
    dp[0] = {1, 0}; 
    for(int mask = 1; mask < (1<<n); mask++){
        for(int i = 0; i < n; i++){
            if(mask & (1<<i)){
                auto prev = dp[mask ^ (1<<i)];
                if(prev.second + w[i] <= x){
                    prev.second += w[i];
                } else {
                    prev.first++;
                    prev.second = w[i];
                }
                dp[mask] = min(dp[mask], prev);
            }
        }
    }
    cout << dp[(1<<n)-1].first << endl;
}
