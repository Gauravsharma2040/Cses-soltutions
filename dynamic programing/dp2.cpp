#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,x;
cin>>n>>x;
vector<int> coins(n);
vector<int> dp(x+1,INT_MAX);
dp[0] = 0;
for(int i=0;i<n;i++) cin>>coins[i];
for(int i=1;i<=x;i++){
    for(auto c : coins){
        if(i-c <0 || dp[i-c] == INT_MAX) continue;
        dp[i] = min(dp[i],dp[i-c]+1);
    }
}
dp[x] == INT_MAX?cout<<-1:cout<<dp[x];
return 0;
}