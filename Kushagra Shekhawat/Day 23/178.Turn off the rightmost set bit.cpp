#include<bits/stdc++.h>
using namespace std;

int turnOffRightMostBit(int a);

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        cout<<turnOffRightMostBit(a)<<endl;
    }
    return 0;
}

int turnOffRightMostBit(int a){
    int mask = a&(~(a-1));  //this extracts the right most bit
    //take xor to turn off right most bit
    return (a^mask);
    // or we could use this a&(a-1) to off the rightmost bit
}