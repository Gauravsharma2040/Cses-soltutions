#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> tops;   // sorted list of tower tops

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // Find tower whose top is > x
        auto it = upper_bound(tops.begin(), tops.end(), x);

        if (it == tops.end()) {
            // No such tower: create new one
            tops.push_back(x);
        } else {
            // Replace tower top
            *it = x;
        }

        // Keep tops sorted
        // (upper_bound ensures updated position is still sorted)
    }

    cout << tops.size() << "\n";
    return 0;
}
