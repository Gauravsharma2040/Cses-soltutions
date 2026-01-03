#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    stack<int> st; // stores indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && x[st.top()] >= x[i]) {
            st.pop();
        }
        if (st.empty())
            cout << 0 << " ";
        else
            cout << st.top() + 1 << " ";

        st.push(i);
    }
    cout << "\n";
    return 0;
}
