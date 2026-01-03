#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int64 r, c;
        cin >> r >> c;
        int64 m = max(r, c);
        int64 ans;
        if (m % 2 == 0) {
            if (r == m) ans = m * m - (c - 1);
            else        ans = (m - 1) * (m - 1) + r;
        } else {
            if (c == m) ans = m * m - (r - 1);
            else        ans = (m - 1) * (m - 1) + c;
        }
        cout << ans << '\n';
    }
    return 0;
}
