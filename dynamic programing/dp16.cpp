#include <bits/stdc++.h>
using namespace std;
static const long long mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long total = 1LL * n * (n + 1) / 2;
    if (total % 2 != 0) {
        cout << 0;
        return 0;
    }
    long long target = total / 2 - n;
    if (target < 0) {
        cout << 0;
        return 0;
    }
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int x = 1; x <= n - 1; x++) {
        for (int s = target; s >= x; s--) {
            dp[s] = (dp[s] + dp[s - x]) % mod;
        }
    }
    cout << dp[target];
    return 0;
}
