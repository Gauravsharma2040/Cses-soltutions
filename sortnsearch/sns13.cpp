#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        return splitmix64(x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int,int,custom_hash> last;
    int l = 0;
    int best = 0;

    for (int r = 0; r < n; r++) {
        if (last.count(a[r])) {
            l = max(l, last[a[r]] + 1);
        }
        last[a[r]] = r;
        best = max(best, r - l + 1);
    }

    cout << best << "\n";
    return 0;
}
