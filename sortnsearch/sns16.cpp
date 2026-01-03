#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int,int> last;
    long long ans = 0;

    int l = 0;
    for (int r = 0; r < n; r++) {
        if (last.count(a[r])) {
            l = max(l, last[a[r]] + 1);
        }

        last[a[r]] = r;
        ans += (r - l + 1);   // number of distinct-element subarrays ending at r
    }

    cout << ans << "\n";
    return 0;
}
