#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    vector<int> time(t);
    for(int i=0;i<t;i++){
        cin>>time[i];
    }
    long long tt = accumulate(time.begin(),time.end(),0LL);
    long long m = 2*(*max_element(time.begin(),time.end()));
    cout<<max(tt,m)<<endl;
}