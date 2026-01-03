#include <iostream>
using namespace std;

int collatz(long long int n) {
    cout <<n<<" ";
    if (n == 0) {
        return 0;
    }
     else if(n==1){
        return 1;
    } 
    else {
        do {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = (3 * n) + 1;
            }
            cout << n << " ";  
        } while (n != 1);
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    collatz(n);
    return 0;
}
