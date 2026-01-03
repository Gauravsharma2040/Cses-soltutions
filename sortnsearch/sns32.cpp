#include<bits/stdc++.h>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        return splitmix64(x);
    }
};
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,k;
cin>>n>>k;
if (k == 0) {
    cout << 0;
    return 0;
}
vector<int> nums(n);
unordered_map<int,int,custom_hash> un1;
for(int i=0;i<n;i++) cin>>nums[i];
int left =0;
int right =0;
long long count=0;
while(right<n){
    un1[nums[right]]++;
    right++;
if(un1.size()<=k){
    count+=right-left;
}
else{
    while(un1.size()>k){
    un1[nums[left]]--;
    if(un1[nums[left]]==0) un1.erase(nums[left]);
    left++;
}
count+=right-left;
}
}
cout<<count<<" ";
return 0;
}