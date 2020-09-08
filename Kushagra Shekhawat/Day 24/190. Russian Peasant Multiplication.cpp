#include<bits/stdc++.h>
using namespace std;

unsigned int RussianPeasant(unsigned int x,unsigned int y);

int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned int x,y;
        cin>>x,y;
        cout<<RussianPeasant(x,y)<<endl;
    }
}

unsigned int RussianPeasant(unsigned int x,unsigned int y){
    int res = 0;
    while(y>0){
        if(y & 1)
            res+=x;
        x = x<<1;
        y = y>>1;
    }
    return res;
}