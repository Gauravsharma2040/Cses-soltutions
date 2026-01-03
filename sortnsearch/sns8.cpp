#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long best = LLONG_MIN;
    long long current = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        current = max(x, current + x);
        best = max(best, current);
    }

    cout << best << "\n";
    return 0;
}
