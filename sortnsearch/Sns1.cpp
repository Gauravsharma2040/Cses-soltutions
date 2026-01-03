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
    set<long long> s;

    int n;
    cin >> n;

    int count = 0;
    while (n--) {
        long long a;
        cin >> a;
        if (!s.count(a)) {
            s.insert(a);
            count++;
        }
    }
    cout << count;
}
