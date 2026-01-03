#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<long long,int>> events;
    events.reserve(2*n);
    
    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        events.emplace_back(a, +1); // arrival
        events.emplace_back(b, -1); // leaving
    }
    
    sort(events.begin(), events.end()); // times are distinct as per statement
    
    long long cur = 0, best = 0;
    for (auto& e : events) {
        cur += e.second;
        best = max(best, cur);
    }
    
    cout << best << '\n';
    return 0;
}
