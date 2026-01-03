#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    long long moves = 0;
    long long max_so_far = x[0];

    for (int i = 1; i < n; i++) {
        if (x[i] < max_so_far) {
            moves += (max_so_far - x[i]);
        } else {
            max_so_far = x[i];
        }
    }

    cout << moves << "\n";
    return 0;
}
