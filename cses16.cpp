#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    long long total = accumulate(nums.begin(), nums.end(), 0LL);
    long long best = LLONG_MAX;

    for (int mask = 0; mask < (1 << n); mask++) {
        long long group1 = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) group1 += nums[i];
        }
        long long group2 = total - group1;
        best = min(best, abs(group1 - group2));
    }

    cout << best << "\n";
    return 0;
}
