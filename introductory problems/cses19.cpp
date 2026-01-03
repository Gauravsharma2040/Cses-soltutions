#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        // Basic feasibility checks
        if (a + b > n) {
            cout << "NO\n";
            continue;
        }
        // Either both zero, or both positive (non-zero).
        if ((a == 0 && b != 0) || (b == 0 && a != 0)) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        // Trivial all-tie case
        if (a == 0 && b == 0) {
            for (int i = 1; i <= n; ++i) {
                if (i > 1) cout << ' ';
                cout << i;
            }
            cout << '\n';
            for (int i = 1; i <= n; ++i) {
                if (i > 1) cout << ' ';
                cout << i;
            }
            cout << '\n';
            continue;
        }

        int tie = n - a - b;      // number of fixed positions
        int m = a + b;            // remaining block length

        vector<int> P(n + 1), Q(n + 1); // 1-indexed

        // P is identity 1..n
        for (int i = 1; i <= n; ++i) P[i] = i;

        // First tie positions: same values
        for (int i = 1; i <= tie; ++i) Q[i] = i;

        // Remaining values are tie+1 .. n
        // Create Q by cyclically shifting this block left by 'a' positions
        // (so Q[tie + 1 + k] = tie + 1 + ((k + a) % m))
        for (int k = 0; k < m; ++k) {
            int pos = tie + 1 + k;                 // position in arrays
            int from_idx = (k + a) % m;            // index inside remaining block
            int value = tie + 1 + from_idx;       // actual number to place
            Q[pos] = value;
        }

        // Output P and Q as space-separated permutations
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << P[i];
        }
        cout << '\n';
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << Q[i];
        }
        cout << '\n';
    }
    return 0;
}
