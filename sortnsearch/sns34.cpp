#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,k;
cin>>n>>k;
vector<pair<int,int>> movs(n);
multiset<int> tim;
int count =0;
for(int i=0;i<n;i++){
    cin>>movs[i].first>>movs[i].second;
}
sort(movs.begin(), movs.end(), [](const pair<int,int>& a,
                                 const pair<int,int>& b) {
    if (a.second == b.second)
        return a.first < b.first;   
    return a.second < b.second;   
});
for(int i=0;i<n;i++){
    auto it = tim.upper_bound(movs[i].first);
    if(it!=tim.begin()){
        --it;
        tim.erase(it);
        tim.insert(movs[i].second);
        count++; 
    }
    else if(tim.size()<k){
        tim.insert(movs[i].second);
        count++;
        continue;
    }
}
cout<<count<<" ";
return 0;
}