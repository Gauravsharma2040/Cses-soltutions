#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m;
cin>>n>>m;
vector<long long> nums(n);
vector<long long> pref(n+1,0);
for(int i=0;i<n;i++){
    long long a;
    cin>>a;
    nums[i] = a;
    pref[i+1]  = nums[i]+pref[i];
}
while(m--){
    int a,b;
    cin>>a>>b;
    cout<<pref[b]-pref[a-1]<<endl;
}
return 0;
}