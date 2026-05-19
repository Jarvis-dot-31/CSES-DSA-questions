#include <bits/stdc++.h>
using namespace std;

string num;
long long dp[20][11][2][2];

long long solve(int pos, int prev, int tight, int started) {
    if (pos == num.size()) return 1;

    if (dp[pos][prev][tight][started] != -1)
        return dp[pos][prev][tight][started];

    int limit = (tight ? num[pos] - '0' : 9);
    long long ans = 0;

    for (int d = 0; d <= limit; d++) {
        int new_tight = tight && (d == limit);

        if (!started && d == 0) {
            ans += solve(pos + 1, 10, new_tight, 0);
        } else {
            if (d == prev) continue;
            ans += solve(pos + 1, d, new_tight, 1);
        }
    }

    return dp[pos][prev][tight][started] = ans;
}

long long countNumbers(long long n) {
    num = to_string(n);
    memset(dp, -1, sizeof(dp));
    return solve(0, 10, 1, 0);
}

int main() {
    long long L, R;
    cin >> L >> R;

    cout << countNumbers(R) - countNumbers(L - 1) << endl;
}