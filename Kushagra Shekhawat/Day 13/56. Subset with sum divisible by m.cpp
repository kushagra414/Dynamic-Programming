#include<bits/stdc++.h>
using namespace std;

bool isDivisible(int arr[],int sum,int size,int divisor);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>N>>K;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    int sum = accumulate(arr,arr+N,0);
	    cout<<isDivisible(arr,sum,N,K)<<endl;
	}
	return 0;
}

bool isDivisible(int arr[],int sum,int size,int divisor){
    if(size<=0 or sum<=0){
        return false;
    }else if(sum%divisor==0){
        return true;
    }
    isDivisible(arr,sum-arr[size-1],size-1,divisor) or 
    isDivisible(arr,sum,size-1,divisor);
}