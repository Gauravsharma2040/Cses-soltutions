#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,k;
cin>>n>>k;
vector<int> nums(n);
for(int i=0;i<n;i++){
    cin>>nums[i];
}
long long high = accumulate(nums.begin(),nums.end(),0LL);
bool fes = false;
long long low =*max_element(nums.begin(),nums.end());
long long ans =high;
while(low<=high){
    int count =1;
    long long pref=0;
    long long mid = low+(high-low)/2;
for(int i=0;i<n;i++){
  if(pref+nums[i]>mid){
    count++;
    pref=nums[i];
  }
  else{
    pref+=nums[i];
  }
}
 if(count<=k){
    ans = mid;
    high = mid-1;
  } 
 else {
    low = mid+1;
    }   
}
cout<<ans<<" ";
return 0;
}