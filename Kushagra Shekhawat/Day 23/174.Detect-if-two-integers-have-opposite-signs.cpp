#include<bits/stdc++.h>
using namespace std;

#define INT 32

bool areOpposite(int a,int b);

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<areOpposite(a,b)<<endl;
    }
    return 0;
}

bool areOpposite(int a,int b){
    return (a^b)<0;
}