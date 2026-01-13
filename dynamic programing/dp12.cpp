#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int a;
int b;
cin>>a>>b;
vector<vector<int>> dp(a+1, vector<int>(b+1,1e9));
for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
        if(i==j) dp[i][j] = 0;
        else{
            int hor =1e9,ver = 1e9;
        for(int k=1;k<=(i/2);k++){
            hor = min(hor,1+dp[i-k][j]+dp[k][j]);
        }
        for(int k=1;k<=(j/2);k++){
            ver = min(ver,1+dp[i][j-k]+dp[i][k]);
        }
        dp[i][j] = min(hor,ver);
    }
    }
}
cout<<dp[a][b]<<endl;
return 0;
}