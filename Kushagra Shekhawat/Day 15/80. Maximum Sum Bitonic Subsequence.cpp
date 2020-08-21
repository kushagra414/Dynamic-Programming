#include<bits/stdc++.h>
using namespace std;

struct MSBS{
    int val,LIS,LDS;
};

int findMSBS(MSBS arr[],int N);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    MSBS arr[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i].val;
	        arr[i].LIS = arr[i].val;
	        arr[i].LDS = arr[i].val;
	    }
	    cout<<findMSBS(arr,N)<<endl;
	}
	return 0;
}

int findMSBS(MSBS arr[],int n){
    int maxBitonic=INT_MIN;
    //Find LIS
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i].val>arr[j].val)
                arr[i].LIS = max(arr[i].LIS,
                arr[j].LIS+arr[i].val);
            
        }
    }
    //Find LDS
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i].val>arr[j].val)
                arr[i].LDS = max(arr[i].LDS,
                arr[j].LDS+arr[i].val);
            
        }
    }
    for(int i=0;i<n;i++){
        maxBitonic = max(arr[i].LIS+arr[i].LDS-arr[i].val
        ,maxBitonic);
    }
    return maxBitonic;
}