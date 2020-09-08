#include<bits/stdc++.h>
using namespace std;

#define INT 32

int addOne(int a);

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        cout<<addOne(a)<<endl;
    }
    return 0;
}

int addOne(int a){
    bitset<INT> binaryRepresentation(a);
    if(a%2==0)
        binaryRepresentation[0]=1;
    else{
        for(int i=0;i<INT;i++){
            if(binaryRepresentation[i]==0){
                    binaryRepresentation[i]=1;
                    while(i--){
                        binaryRepresentation[i]=0;
                    }
                    break;
                }
        }
    }
    //https://stackoverflow.com/questions/49081800/convert-negative-binary-number-to-decimal
    //These 2 lines of code below are really complex. First we convert the negative number to unsigned long int.
    //After that we will conver it to signed int to get the correct ans.
    //We can do this because of non-circular nature unsigned int and circular nature of int data type.
    auto ul = stoul(binaryRepresentation.to_string(),nullptr,2); //unsigned long. string to unsigned long
    return ul; //converting to int
}