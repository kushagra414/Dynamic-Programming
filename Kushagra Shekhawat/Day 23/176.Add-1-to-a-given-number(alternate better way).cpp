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

int addOne(int x){
    //To understand the below line you must know 2 points.
    //1. what is 2s complement? ---> 2's complement is the number that must be added to 'x' to make it exponential factor of 2
    //Eg:- here is a binary number 0101(5) it's 2s complement is 1011(11). When we add 5+11=16 = 2^4.
    //2. What is 1s complement? ---> 1's complement is the number that must be added to 'x' to make it exponential factor of 2 minus 1.
    //Eg:- here is a binary number 0101(5) it's 1s complement is 1010(10). When we add 5+10=15 = 2^4-1.
    //So using the above facts we can deduce the below formula.
    //2s complement of x = 2^N - x.     --(i)
    //1s complement of x = 2^N - x -1.  --(ii)
    //First take 1s complement then take 2s complement of the 1s complement i.e. 2s complement(1s complement).
    // 2s complement(1s complement)  ===>   subsituting eq (ii)  2s complement(2^N-x-1)   -- (iii)
    //2s complement(1s complement) =  2^N - (2^N -x -1)   ===> using eq (i)
    //Finally you can see that 2s complement(1s complement) = x + 1.
    //That's why this formula works!
    return -(~x);
}