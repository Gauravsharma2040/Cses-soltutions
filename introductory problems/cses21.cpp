#include <bits/stdc++.h>
using namespace std;

static const int dr[8] = {2,2,-2,-2,1,1,-1,-1};
static const int dc[8] = {1,-1,1,-1,2,-2,2,-2};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Use 1D array for better cache locality
    vector<int> dist(n*n, -1);
    auto idx = [&](int r, int c) { return r*n + c; };

    queue<int> q;
    dist[0] = 0;        // (0,0)
    q.push(0);          // store index as integer

    while (!q.empty()) {
        int u = q.front(); q.pop();
        int r = u / n;
        int c = u % n;
        int d = dist[u];

        // explore all 8 knight moves
        for (int k = 0; k < 8; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                int v = idx(nr, nc);
                if (dist[v] == -1) {
                    dist[v] = d + 1;
                    q.push(v);
                }
            }
        }
    }

    // Output matrix
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << dist[idx(r,c)] << " ";
        }
        cout << "\n";
    }
}
