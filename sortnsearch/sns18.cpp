#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    list<int> people;
    for (int i = 1; i <= n; i++) people.push_back(i);

    auto it = people.begin();
    while (!people.empty()) {
        // move one step
        it++;
        if (it == people.end()) it = people.begin();

        // print and remove
        cout << *it << " ";
        it = people.erase(it);
        if (it == people.end()) it = people.begin();
    }
}
