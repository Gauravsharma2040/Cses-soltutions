#include<bits/stdc++.h>
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
    segment[ind] = max(segment[2*ind+1], segment[2*ind+2]);
}
long long query(int ind, int low, int high, int l, int r) {
    if (r < low || high < l) return LLONG_MIN;
    if (l <= low && high <= r) return segment[ind];
    int mid = (low + high) / 2;
    long long left  = query(2*ind+1, low, mid, l, r);
    long long right = query(2*ind+2, mid+1, high, l, r);
    return max(left, right);
}
void update(int ind, int low, int high, int pos, long long val) {
    if (low == high) {
        segment[ind] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (pos <= mid)
        update(2*ind+1, low, mid, pos, val);
    else
        update(2*ind+2, mid+1, high, pos, val);

    segment[ind] = max(segment[2*ind+1], segment[2*ind+2]);
}
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
vector<int> mountain(n);
for(int i=0;i<n;i++) cin>>mountain[i];
vector<int> L(n), R(n);
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && mountain[st.top()] < mountain[i]) st.pop();
    L[i] = st.empty() ? -1 : st.top();
    st.push(i);
}
while (!st.empty()) st.pop();
for (int i = n-1; i >= 0; i--) {
    while (!st.empty() && mountain[st.top()] < mountain[i])
        st.pop();
    R[i] = st.empty() ? n : st.top();
    st.push(i);
}
vector<int> order(n);
    iota(order.begin(),order.end(),0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return mountain[a] < mountain[b];
    });
    for (int i = 0; i < 4 * n; i++) segment[i] = 0;
    vector<int> dp(n, 1);
    for (int idx : order) {
        int best = 0;
        if (L[idx] + 1 <= idx - 1) {
            best = max(best,
                (int)query(0, 0, n - 1, L[idx] + 1, idx - 1)
            );
        }
        if (idx + 1 <= R[idx] - 1) {
            best = max(best,
                (int)query(0, 0, n - 1, idx + 1, R[idx] - 1)
            );
        }
        dp[idx] = 1 + best;
        update(0, 0, n - 1, idx, dp[idx]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    cout << ans << "\n";
}