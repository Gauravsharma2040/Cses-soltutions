#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        tickets.insert(h);
    }

    while (m--) {
        int t;
        cin >> t;

        // find first ticket > t
        auto it = tickets.upper_bound(t);

        if (it == tickets.begin()) {
            // no ticket <= t
            cout << -1 << "\n";
        } else {
            // step back to ticket <= t
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
}
