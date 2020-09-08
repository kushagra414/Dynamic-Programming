#include<bits/stdc++.h>
using namespace std;

int findModulus(unsigned int a,unsigned int powerOf2);

int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned int a,powerOf2;
        cin>>a>>powerOf2;
        cout<<findModulus(a,powerOf2)<<endl;
    }
    return 0;
}

int findModulus(unsigned int a,unsigned int powerOf2){
    int shift = __builtin_clz(powerOf2)+1;
    a = a<<shift;
    powerOf2 = powerOf2<<shift;
    a = a>>shift;
    powerOf2 = powerOf2>>shift;
    return (a | powerOf2);

    //or simply return
    //return (a&(powerOf2-1));
}