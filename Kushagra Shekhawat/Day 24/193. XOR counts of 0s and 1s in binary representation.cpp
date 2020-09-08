#include<bits/stdc++.h>
using namespace std;

int XOROf0sand1s(unsigned int x);

int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned int x;
        cin>>x;
        XOROf0sand1s(x);
    }
}

int XOROf0sand1s(unsigned int x){
    int ones = __builtin_popcount(x);
    int leadingZeros = __builtin_clz(x);
    int zeros = sizeof(unsigned int)*8 - leadingZeros;
    return ones ^ zeros;
}