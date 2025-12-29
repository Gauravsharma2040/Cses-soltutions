#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long total = (long long)n * (n + 1) / 2;
    long long sum = 0;
    int num;

    for (int i = 0; i < n - 1; i++) {
        cin >> num;
        sum += num;
    }

    cout << (total - sum) << endl;

    return 0;
}
