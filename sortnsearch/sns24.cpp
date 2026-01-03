#include<bits/stdc++.h>
using namespace std;
int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>> task(n);
    for(int i=0;i<n;i++){
        cin>>task[i].first;
        cin>>task[i].second;
    }
    sort(task.begin(), task.end(),
    [](const auto& a, const auto& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    ); 
    long long time = 0;
    long long reward =0;
    for(int i=0;i<n;i++){
        time+=task[i].first;
        reward+=(task[i].second - time);

    }
    cout<<reward;

}