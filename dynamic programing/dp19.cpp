#include <bits/stdc++.h>
using namespace std;
struct Project {
    long long s, e, p;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Project> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].s >> a[i].e >> a[i].p;
    }
    sort(a.begin(), a.end(), [](const Project& x, const Project& y) {
        return x.e < y.e;
    });
    vector<long long> ends(n);
    for (int i = 0; i < n; ++i) ends[i] = a[i].e;
    vector<long long> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        long long take = a[i].p;
        int j = lower_bound(ends.begin(), ends.end(), a[i].s) - ends.begin() - 1;
        if (j >= 0) take += dp[j];
        long long skip = (i > 0 ? dp[i-1] : 0);
        dp[i] = max(skip, take);
    }
    cout << dp[n-1] << "\n";
    return 0;
}
