#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,a,b;
cin>>n>>a>>b;
vector<int> nums(n);
vector<long long> pref(n+1); 
multiset<long long> ms;
pref[0] =0;
for(int i=0 ;i<n;i++){
    cin>>nums[i];
    pref[i+1] = pref[i]+nums[i];
}
long long best = LLONG_MIN;
ms.insert(pref[0]);
for (int curr = a; curr <= n; curr++) {
    long long cur_max = pref[curr] - *ms.begin();
    best = max(best, cur_max);
    int remove_idx = curr - b;
    if (remove_idx >= 0) {
        auto it = ms.find(pref[remove_idx]);
        if (it != ms.end()) ms.erase(it);
    }
    int add_idx = curr - a + 1;
    if (add_idx <= n) {
        ms.insert(pref[add_idx]);
    }
}
cout<<best<<" ";
return 0;
}