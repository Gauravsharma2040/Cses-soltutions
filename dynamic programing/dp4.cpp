#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    vector<long long> ways(x + 1, 0);
    ways[0] = 1;
    for (auto coin : coins) {
    for (auto sum = coin; sum <= x; sum++) {
        ways[sum] += (ways[sum - coin]) %MOD;
    }
}
    cout<<ways[x]%MOD<<' ';
    return 0;
}

