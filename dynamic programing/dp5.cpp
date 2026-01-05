#include<bits/stdc++.h>
using namespace std;
int extract(long long n) {
    if (n < 10) return n;
    return max(int(n % 10), extract(n / 10));
}

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
long long n;
cin>>n;
long long count=0;
while(n>0){
    n = n - extract(n);
    count++;
}
cout<<count<<" ";
return 0;
}