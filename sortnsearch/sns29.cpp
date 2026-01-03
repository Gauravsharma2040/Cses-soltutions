#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    long long sum = 0;
    int l = 0;
    long long count = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > x) {
           sum -= a[l];
            l++;
        }
        if (sum == x) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
