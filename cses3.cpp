#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char str[100000000];
    cin>>str;
    int n=strlen(str);
    int k=1;
    int j=0;
    for(int i=0;i<=n-1;i++){
        if(str[i] == str[i+1]){
            k++;
        }
        else{
            k=1;
            }
        if(k>j){
            j=k;
            
        }
    }
    cout<<j;
    return 0;
}
