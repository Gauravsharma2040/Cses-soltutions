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
    long long x;
    cin >> n >> x;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    unordered_map<long long, long long,custom_hash> freq;
    freq[0] = 1;  
    long long prefix = 0;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        prefix += nums[i];
        if (freq.count(prefix - x)) {
            count += freq[prefix - x];
        }
        freq[prefix]++;
    }

    cout << count << "\n";
    return 0;
}

