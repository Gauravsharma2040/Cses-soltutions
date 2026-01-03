#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        long long k;
        cin >> k;

        long long digit = 1;
        long long count = 9;
        long long start = 1;

        // Find digit block
        while (k > digit * count) {
            k -= digit * count;
            digit++;
            count *= 10;
            start *= 10;
        }

        // Locate the exact number
        long long index = k - 1;
        long long number = start + index / digit;
        int pos = index % digit;

        // Output the digit
        cout << to_string(number)[pos] << "\n";
    }
}
