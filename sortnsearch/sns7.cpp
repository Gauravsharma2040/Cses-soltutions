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

    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) 
        cin >> nums[i];

    unordered_map<int, int,custom_hash> mp; // value -> index

    for (int i = 0; i < n; i++) {
        int need = target - nums[i];

        // check if complement exists
        if (mp.count(need)) {
            cout << mp[need] + 1 << " " << i + 1 << "\n";
            return 0;
        }

        mp[nums[i]] = i;  // store index
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
