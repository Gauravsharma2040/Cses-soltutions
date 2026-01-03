#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    sort(p.begin(), p.end());
    long long t = p[n/2]; // median (if n even, this is the upper median; lower median also ok)
    long long cost = 0;
    for (int i = 0; i < n; ++i) cost += llabs(p[i] - t);
    cout << cost << "\n";
    return 0;
}
