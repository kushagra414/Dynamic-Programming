#include<bits/stdc++.h>
using namespace std;

int toggleKthBit(int x,int k);

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
        cout<<toggleKthBit(x,k)<<endl;
    }
}

int toggleKthBit(int x,int k){
    return x ^ (1<<(k-1));
}