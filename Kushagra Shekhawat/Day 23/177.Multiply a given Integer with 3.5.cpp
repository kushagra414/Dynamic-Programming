#include<bits/stdc++.h>
using namespace std;

#define INT 32

int multiplyBy3_5(int a);

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        cout<<multiplyBy3_5(a)<<endl;
    }
    return 0;
}

int multiplyBy3_5(int a){
    int a2,aBy2;
    // break the number as 2*x + x + 0.5x
    //to get 2x do a left shift by 1
    a2 = a<<1;
    //to get 0.5 do a right shift by 1
    aBy2 = a>>1;
    // now add 2x + 0.5x + x
    return (a2+aBy2+a);
    
}