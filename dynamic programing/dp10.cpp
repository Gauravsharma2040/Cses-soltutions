#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m;
cin>>n>>m;
vector<int> arr(n);
vector<int> nums(m);
for(int i=0;i<n;i++) cin>>arr[i];
for(int i=0;i<m;i++) cin>>nums[i];
vector<vector<int>> dp(n+1,vector<int>(m+1));
dp[0][0] = 0;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(arr[i-1]==nums[j-1]){
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
    }
}
int i = n;
int j = m ;
vector<int> lcs;
while (i > 0 && j > 0) {
    if (arr[i-1] == nums[j-1]) {
        lcs.push_back(arr[i-1]);
        i--; 
        j--;
    } else if (dp[i-1][j] >= dp[i][j-1]) {
        i--;
    } else {
        j--;
    }
}
reverse(lcs.begin(), lcs.end());
cout<<dp[n][m]<<endl;
for(int i=0;i<lcs.size();i++){
 cout<<lcs[i]<<" ";
}
return 0;
}