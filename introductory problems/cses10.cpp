#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long int n;
    cin>>n;
    long long int res=0;
    for(long long int i = 5 ; i<=n ; i*=5){
    res += n/i;
    }
    cout<<res;
    return 0 ;
}