#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
vector<vector<char>> grid(n,vector<char>(n));
for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>grid[i][j];
vector<pair<int,int>> cur;
string ans = "";
cur.push_back({0,0});
ans += grid[0][0];
for(int i=0;i< 2*n-2;i++){
    char best = 'Z'+1;
    vector<pair<int,int>> next;
    static bool seen[3000][3000];  
    for (auto [x,y] : cur){
        if (x+1 < n) best = min(best, grid[x+1][y]);
        if (y+1 < n) best = min(best, grid[x][y+1]);
    }
    for (auto [x,y] : cur){
        if (x+1 < n && grid[x+1][y] == best && !seen[x+1][y]){
            seen[x+1][y] = true;
            next.push_back({x+1,y});
        }
        if (y+1 < n && grid[x][y+1] == best && !seen[x][y+1]) {
            seen[x][y+1] = true;
            next.push_back({x,y+1});
        }
    }
ans+=best; 
cur= next;
}    
cout<<ans<<endl;
return 0;
}