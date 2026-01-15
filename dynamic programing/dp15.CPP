#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<long long> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = x[i];
    }
    for (int r = 1; r < n; r++) {
        for (int l = r - 1; l >= 0; l--) {
            dp[l] = max(
                x[l] - dp[l + 1],
                x[r] - dp[l]
            );
        }
    }
    long long total = accumulate(x.begin(), x.end(), 0LL);
    long long first = (total + dp[0]) / 2;
    cout << first << "\n";
}
