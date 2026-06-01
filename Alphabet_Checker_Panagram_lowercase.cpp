#include<iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int flag=0;
    cout<<"Enter a String";
    cin>>s;
    for(char c : s) {
        flag = flag | (1<< (c-'a'));
    }
    if (flag==(1<<26)-1){
        cout<<"YES"<<endl;}
    else{
        cout<<"NO"<<endl;
        }
}
