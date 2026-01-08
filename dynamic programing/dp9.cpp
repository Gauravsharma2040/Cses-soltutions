#include <bits/stdc++.h>
using namespace std;
static const long long MOD = 1e9 + 7;
static const int MAXN = 1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<long long>> dp(MAXN + 1, vector<long long>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        dp[i][0] = (2 * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + 4 * dp[i-1][1]) % MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
}
