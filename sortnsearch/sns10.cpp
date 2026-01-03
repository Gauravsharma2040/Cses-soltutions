#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    ll reachable = 1; // smallest sum we cannot make so far

    for (ll c : a) {
        if (c > reachable) break;
        reachable += c;
    }

    cout << reachable << "\n";
    return 0;
}
