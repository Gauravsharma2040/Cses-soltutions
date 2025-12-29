#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int to, int aux, vector<pair<int,int>>& moves) {
    if (n == 0) return;

    // Move n-1 disks from 'from' to 'aux' using 'to' as helper
    hanoi(n-1, from, aux, to, moves);

    // Move the nth disk from 'from' to 'to'
    moves.push_back({from, to});

    // Move the n-1 disks from 'aux' to 'to' using 'from' as helper
    hanoi(n-1, aux, to, from, moves);
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<pair<int,int>> moves;
    hanoi(n, 1, 3, 2, moves);

    cout << moves.size() << "\n";
    for (auto [a, b] : moves)
        cout << a << " " << b << "\n";

    return 0;
}
