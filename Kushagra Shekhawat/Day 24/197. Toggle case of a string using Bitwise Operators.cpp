#include<bits/stdc++.h>
using namespace std;

string toggleCases(string x);

int main(){
    int t;
    cin>>t;
    while(t--){
        string x;
        cin>>x;
        cout<<toggleCases(x)<<endl;
    }
}

string toggleCases(string x){
    for(int i=0;i<x.length();i++){
        x[i] = x[i]^32;
    }
    return x;
}