#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void add(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    // find smallest index with prefix sum >= k (1-based k)
    int kth(int k) {
        int idx = 0;
        // compute largest power of two <= n
        int mask = 1;
        while ((mask << 1) <= n) mask <<= 1;
        for (; mask; mask >>= 1) {
            int t = idx + mask;
            if (t <= n && bit[t] < k) {
                idx = t;
                k -= bit[t];
            }
        }
        return idx + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    Fenwick fw(n);
    for (int i = 1; i <= n; ++i) fw.add(i, 1);

    vector<int> ans;
    ans.reserve(n);
    long long pos = 0; // 0-indexed position among alive persons

    for (int alive = n; alive >= 1; --alive) {
        pos = (pos + k) % alive;      // skip k and remove next -> index pos (0-based)
        int target = (int)pos + 1;    // 1-based order statistic
        int id = fw.kth(target);
        ans.push_back(id);
        fw.add(id, -1);               // remove
        // next pos remains at the same numeric index (because after removal
        // people shift left); we keep pos as-is for next iteration.
    }

    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
