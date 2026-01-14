#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
vector<int> coins(n);
for(int i=0;i<n;i++) cin>>coins[i];
int maxSum = accumulate(coins.begin(), coins.end(), 0ll);
vector<bool> dp(maxSum+1,false);
dp[0] = true;
for (int coin : coins){
        for (int s = maxSum; s >= coin; s--) {
            if (dp[s - coin]) dp[s] = true;
        }
    }
    vector<int> res;
    for (int s = 1; s <= maxSum; s++) {
        if (dp[s]) res.push_back(s);
    }
    cout<<res.size()<<"\n";
    for(int s : res) cout << s << " ";
    cout<<"\n";
return 0;
}