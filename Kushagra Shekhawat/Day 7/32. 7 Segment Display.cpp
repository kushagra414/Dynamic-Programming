#include<bits/stdc++.h>
using namespace std;

int calculateSegments(string arr,int N);
string findMinNumber(int N,int totalSegments);
int FindMinSegment(int segments,int digitsLeft);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    string num;
	    cin>>num;
        int totalSegments = calculateSegments(num,N);
        cout<<findMinNumber(N,totalSegments)<<endl;
	}
	return 0;
}

int calculateSegments(string arr,int N){
    int totalSegments=0;
    for(int i=0;i<N;i++){
        int segments;
        switch(arr[i]){
            case '0': segments=6;
                break;
            case '1': segments=2;
                break;
            case '2': segments=5;
                break;
            case '3': segments=5;
                break;
            case '4': segments=4;
                break;
            case '5': segments=5;
                break;
            case '6': segments=6;
                break;
            case '7': segments=3;
                break;
            case '8': segments=7;
                break;
            case '9': segments=5;
                break;
            default: segments=8;
                break;
        }
        totalSegments+=segments;
    }
    return totalSegments;
}

int FindMinSegment(int segments,int digitsLeft){
    //check 0
    for(int i=0;i<10;i++){
        int segmentsLeft = segments-calculateSegments(to_string(i),1);
        //LowerLimit and Upper Limit
        if(segmentsLeft-2*(digitsLeft-1)>=0 and segmentsLeft-7*(digitsLeft-1)<=0)
            return i;
    }
}

string findMinNumber(int N,int totalSegments){
    string num="";
    for(int i=0;i<N;i++){
        //Check what number we can put at current place.
        int minNum = FindMinSegment(totalSegments,N-i);
        int segmentUsed = calculateSegments(to_string(minNum),1);
        totalSegments-=segmentUsed;
        num+=to_string(minNum);
    }
    return num;
}