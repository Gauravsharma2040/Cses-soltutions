#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<string> ans(n, string(m, '?'));
    const string colors = "ABCD";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (char c : colors) {
                if (c == grid[i][j]) continue; // must differ from original

                // up conflict
                if (i > 0 && ans[i-1][j] == c) continue;

                // left conflict
                if (j > 0 && ans[i][j-1] == c) continue;

                ans[i][j] = c;
                break;
            }
        }
    }

    // Always solvable (4 colors > max needed)
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";

    return 0;
}
