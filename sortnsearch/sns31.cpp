#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<long long,int> mp;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    long long pref = 0;
    long long count = 0;
    mp[0] = 1;  
    for(int i = 0; i < n; i++){
        pref += nums[i];
        long long rem = pref % n;
        if (rem < 0) rem += n;
        if (mp.count(rem)) {
            count += mp[rem];
        }
        mp[rem]++;   
    }
    cout << count << "\n";
    return 0;
}
