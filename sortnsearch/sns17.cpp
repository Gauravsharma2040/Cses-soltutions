#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<ll, ll> freq;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        freq[x]++;
    }

    ll ans = 1;
    for (auto &p : freq) {
        ll f = p.second;
        ans = (ans * (f + 1)) % MOD;  // f+1 choices for this value
    }

    ans = (ans - 1 + MOD) % MOD; // remove empty subsequence

    cout << ans << "\n";
    return 0;
}
