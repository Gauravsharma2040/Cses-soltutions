#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long int t;
    cin>>t;
    while(t--){
        long int a;
        long int b;
        cin>>a;
        cin>>b;
        if((a+b)%3==0 && 2 * min(a, b) >= max(a, b)){
            cout<<"YES"<<" ";
        }
        else{
            cout<<"NO"<<" ";
        }
    }
    return 0;
}