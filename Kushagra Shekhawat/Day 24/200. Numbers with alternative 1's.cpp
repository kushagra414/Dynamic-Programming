#include<bits/stdc++.h>
using namespace std;

void printAltOnes(vector<int> altOnes);
void findNumWithNoAltZeros(int n);
bool hasConsecutiveOnes(int num, bool isOdd);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int num;
	    cin>>num;
	    findNumWithNoAltZeros(num);
	}
	return 0;
}

void findNumWithNoAltZeros(int n){
    vector<int> AltOnes;
    int isAltOne=1,index=0;
    bool isOdd = true;
    while(sizeof(int)*8 - __builtin_clz(isAltOne)<=n){
        if(!hasConsecutiveOnes(isAltOne,isOdd)){
            AltOnes.push_back(isAltOne);
        }
        isAltOne++;
        isOdd = !isOdd;
    }
    printAltOnes(AltOnes);
}

bool hasConsecutiveOnes(int num, bool wasOdd){
    bool isOdd;
    while(num){
        num = num>>1;
        isOdd = num & 1;
        if(wasOdd and isOdd){
            //There are 2 consecutive ones
            return true;
        }
        wasOdd = isOdd;
    }
    return false;
}

void printAltOnes(vector<int> altOnes){
    for(auto element:altOnes)
        cout<<element<<" ";
    cout<<endl;
}