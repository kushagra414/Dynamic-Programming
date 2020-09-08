#include<bits/stdc++.h>
#define INT 32
using namespace std;

int findTheElement(vector<int> arr);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<findTheElement(arr)<<endl;
    }
}

int findTheElement(vector<int> arr){
    vector<int> countBits(32,0);
    string SingleElement="";
    for(auto element:arr){
        bitset<INT> binaryRepresentation(element);
        cout<<binaryRepresentation<<endl;
        for(int bit=0;bit<INT;bit++){
            if(binaryRepresentation[bit]==1){
                countBits[INT-bit-1]++;
                }
        }
    }
    for(int bits=0;bits<INT;bits++){
        countBits[bits]%=3;
        SingleElement+=to_string(countBits[bits]);
        }
    return stoi(SingleElement,0,2);
}