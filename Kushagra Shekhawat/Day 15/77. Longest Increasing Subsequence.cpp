#include<iostream>
using namespace std;

struct LIS{
    int value,LIS;
};

int findLIS(LIS arr[],int N);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    LIS arr[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i].value;
	        arr[i].LIS = 1;
	    }
	    cout<<findLIS(arr,N)<<endl;
	}
	return 0;
}

int findLIS(LIS arr[],int n){
    int maxLIS=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i].value>arr[j].value and 
            arr[i].LIS<=arr[j].LIS){
                arr[i].LIS = max(arr[j].LIS+1,arr[i].LIS);
                maxLIS = maxLIS>arr[i].LIS?maxLIS:arr[i].LIS;
            }
        }
    }
    return maxLIS;
}