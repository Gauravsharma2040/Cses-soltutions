#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> arr(n+1), pos(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    auto bad = [&](int x)->int {
        if (x < 1 || x >= n) return 0;
        return pos[x] > pos[x+1];
    };

    long long breaks = 0;
    for (int i = 1; i < n; ++i) breaks += bad(i);

    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 1 + breaks << '\n';
            continue;
        }

        int u = arr[a];
        int v = arr[b];
        vector<int> affected = {u-1, u, v-1, v};
        sort(affected.begin(), affected.end());
        affected.erase(unique(affected.begin(), affected.end()), affected.end());

        // subtract old contributions
        for (int x : affected) breaks -= bad(x);

        // perform the swap in arr and pos
        swap(arr[a], arr[b]);
        swap(pos[u], pos[v]);

        // add new contributions
        for (int x : affected) breaks += bad(x);

        cout << 1 + breaks << '\n';
    }
    return 0;
}
