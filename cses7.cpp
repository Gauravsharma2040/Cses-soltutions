#include <bits/stdc++.h>
using namespace std;

long long factorial(long long n) {
    if (n == 1) return 0;
    long long a = n * n;
    return a * (a - 1) / 2;
}

long long subt(long long n) {
    if (n < 3) return 0; // no attacking pairs for n = 1,2
    return 4 * (n - 1) * (n - 2); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        cout << factorial(i) - subt(i) << "\n";
    }

    return 0;
}

