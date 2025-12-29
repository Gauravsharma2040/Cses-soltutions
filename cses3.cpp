#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1000001]; // 1e6 is plenty for this problem
    cin >> str;
    int n = strlen(str);

    int k = 1; // current repetition length
    int j = 1; // max repetition length

    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            k++;
        } else {
            k = 1;
        }
        if (k > j) {
            j = k;
        }
    }

    cout << j;
    return 0;
}

