#include <bits/stdc++.h>
using namespace std;

struct R {
    int l, r, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<R> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].idx = i;
    }

    // Sort by l asc, r desc
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.l == b.l) return a.r > b.r;
        return a.l < b.l;
    });

    vector<int> contains(n, 0), contained(n, 0);

    // PASS 1: check if each interval is contained by some previous one
    int maxR = 0;
    for (auto &it : v) {
        if (it.r <= maxR) {
            contained[it.idx] = 1;
        }
        maxR = max(maxR, it.r);
    }

    // PASS 2: check if each interval contains some next interval
    int minR = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        auto &it = v[i];
        if (it.r >= minR) {
            contains[it.idx] = 1;
        }
        minR = min(minR, it.r);
    }

    for (int x : contains) cout << x << " ";
    cout << "\n";
    for (int x : contained) cout << x << " ";
    cout << "\n";

    return 0;
}
