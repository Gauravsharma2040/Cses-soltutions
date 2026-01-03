#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int l, r, id;
};

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n): n(n), bit(n+1, 0) {}
    void update(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Interval> v(n);
    vector<int> rights;

    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].id = i;
        rights.push_back(v[i].r);
    }

    // coordinate compress r's
    sort(rights.begin(), rights.end());
    rights.erase(unique(rights.begin(), rights.end()), rights.end());
    for (auto &x : v) {
        x.r = lower_bound(rights.begin(), rights.end(), x.r) - rights.begin() + 1;
    }
    int R = rights.size();

    // sort by left asc, right desc
    sort(v.begin(), v.end(), [&](auto &a, auto &b) {
        if (a.l == b.l) return a.r > b.r;
        return a.l < b.l;
    });

    vector<int> contains(n, 0), contained(n, 0);

    // Count "contained" : how many contain i (left -> right)
    Fenwick fw1(R);
    for (int i = 0; i < n; i++) {
        contained[v[i].id] = fw1.query(v[i].r, R);
        fw1.update(v[i].r, 1);
    }

    // Count "contains" : how many i contains (right -> left)
    Fenwick fw2(R);
    for (int i = n - 1; i >= 0; i--) {
        contains[v[i].id] = fw2.query(1, v[i].r);
        fw2.update(v[i].r, 1);
    }

    for (int i = 0; i < n; i++) cout << contains[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << contained[i] << " ";
    cout << "\n";
}


