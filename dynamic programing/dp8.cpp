#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    if (x[0] == 0) {
        for (int v = 1; v <= m; v++) dp[0][v] = 1;
    } else {
        dp[0][x[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int v = 1; v <= m; v++) {
            if (x[i] != 0 && x[i] != v) continue;
            dp[i][v] = dp[i-1][v];
            dp[i][v] = (dp[i][v] + dp[i-1][v-1]) % MOD;
            dp[i][v] = (dp[i][v] + dp[i-1][v+1]) % MOD;
        }
    }
    int ans = 0;
    for (int v = 1; v <= m; v++) {
        ans = (ans + dp[n-1][v]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
