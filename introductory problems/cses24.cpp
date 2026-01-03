#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'A']++;

    auto possible = [&](vector<int>& f, int rem) {
        int mx = 0;
        for (int x : f) mx = max(mx, x);
        return mx <= (rem + 1) / 2;
    };

    vector<char> result(n);
    char last = '?';

    for (int pos = 0; pos < n; pos++) {
        bool placed = false;

        // Try lexicographically smallest available letter
        for (int c = 0; c < 26; c++) {
            if (freq[c] == 0) continue;
            char ch = 'A' + c;

            if (ch == last) continue;  // avoid adjacency

            // simulate choosing this character
            freq[c]--;
            int remaining = n - pos - 1;

            if (possible(freq, remaining)) {
                // valid choice
                result[pos] = ch;
                last = ch;
                placed = true;
                break;
            }

            // undo
            freq[c]++;
        }

        if (!placed) {
            cout << -1 << "\n";
            return 0;
        }
    }

    for (char c : result) cout << c;
    cout << "\n";
}
