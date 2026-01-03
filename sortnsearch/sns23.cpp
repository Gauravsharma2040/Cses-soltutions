#include <bits/stdc++.h>
using namespace std;

bool feasible(long long T, const vector<int>& machines, long long m) {
    long long produced = 0;
    for (long long x : machines) {
        produced += T / x;
        if (produced >= m) return true;  // avoid overflow
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<int> machines(n);
    for (int i = 0; i < n; i++) cin >> machines[i];

    sort(machines.begin(), machines.end());  

    long long low = 0;
    long long high = (long long)machines[0] * m;  

    while (low < high) {
        long long mid = (low + high) / 2;

        if (feasible(mid, machines, m))
            high = mid;       // can do it in mid time → try smaller
        else
            low = mid + 1;    // too slow → need more time
    }

    cout << low << "\n";
}
