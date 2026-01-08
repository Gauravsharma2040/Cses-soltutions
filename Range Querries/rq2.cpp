#include <bits/stdc++.h>
using namespace std;
vector<long long> nums(200005);
vector<long long> segment(4 * 200005);
void build(int ind, int low, int high) {
    if (low == high) {
        segment[ind] = nums[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);
    segment[ind] = min(segment[2*ind+1], segment[2*ind+2]);
}
long long query(int ind, int low, int high, int l, int r) {
    if (r < low || high < l)
        return LLONG_MAX;
    if (l <= low && high <= r)
        return segment[ind];

    int mid = (low + high) / 2;
    long long left  = query(2*ind+1, low, mid, l, r);
    long long right = query(2*ind+2, mid+1, high, l, r);
    return min(left, right);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    build(0, 0, n-1);
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;   
        cout << query(0, 0, n-1, l, r) << '\n';
    }
    return 0;
}
