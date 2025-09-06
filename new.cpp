#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i;
    int j=1;
    int len=s.length();
    if(s.length()==1){
        return 0;
    }
    else if(s.length()>=10){
        
        for(int i=2;i<len-1;i++){
            j++;
        }
            cout<<s[0]<<j<<s[len-1]<<endl;
        }
    else{
        cout<<s<<endl;
    }
}