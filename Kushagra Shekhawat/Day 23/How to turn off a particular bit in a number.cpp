#include<bits/stdc++.h>
using namespace std;

int turnOffKthBit(int a,int k);

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,k;
        cin>>a>>k;
        cout<<turnOffKthBit(a,k)<<endl;
    }
    return 0;
}

int turnOffKthBit(int a,int k){
    return a&(~(1>>(k-1)));
}