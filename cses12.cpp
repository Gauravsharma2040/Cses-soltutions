#include <bits/stdc++.h>
using namespace std;

int main() {
     ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> count(26, 0);
    for (char c : s) count[c - 'A']++;//ACDDDCA

    int oddCount = 0;
    char oddChar = 0;

    // Count how many chars appear odd times
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
            oddChar = 'A' + i;
        }
    }

 
    if (oddCount > 1) {
        cout << "NO SOLUTION";
        return 0;
    }

    string firstHalf = "", middle = "";

    // Build first half
    for (int i = 0; i < 26; i++) {
        firstHalf += string(count[i] / 2, 'A' + i);
    }

    // Add middle if odd-length
    if (oddCount == 1) {
         middle = (oddCount == 1 ? string(1, oddChar) : "");
    }

    // Mirror to make palindrome
    string secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());

    cout << firstHalf + middle + secondHalf;
    return 0;
}
