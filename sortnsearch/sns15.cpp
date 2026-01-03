#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    if (!(cin >> x >> n)) return 0;
    set<int> pos;
    multiset<int> lens;
    pos.insert(0);
    pos.insert(x);
    lens.insert(x);
    for (int i = 0; i < n; ++i) {
        int p; cin >> p;
        auto itR = pos.upper_bound(p);    // first element > p
        auto itL = prev(itR);             // element <= p (actually < p, since p not present)
        int l = *itL;
        int r = *itR;
        // remove the segment length r-l (only one occurrence)
        auto itLen = lens.find(r - l);
        if (itLen != lens.end()) lens.erase(itLen);
        // insert the two new segments
        lens.insert(p - l);
        lens.insert(r - p);
        // insert the new traffic light
        pos.insert(p);
        // current largest segment
        cout << *lens.rbegin();
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}
