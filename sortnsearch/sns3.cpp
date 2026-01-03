#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    int i = 0, j = n - 1;
    int gondolas = 0;
    while (i <= j) {
        if (w[i] + w[j] <= x) {
            // pair lightest + heaviest
            i++;
            j--;
        } else {
            // heaviest must go alone
            j--;
        }
        gondolas++;
    }

    cout << gondolas << "\n";
}
