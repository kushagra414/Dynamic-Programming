#include<bits/stdc++.h>
using namespace std;

int findMinimumCoins(int arr[],int N,int K);

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
	    sort(arr,arr+N);
	    cout<<findMinimumCoins(arr,N,K)<<endl;
	}
	return 0;
}

int findMinimumCoins(int arr[],int N,int K){
    int sum=0,RemovedCoin=INT_MAX;
    int maxDifference = arr[N-1]-arr[0];
    if(maxDifference<=K)
        return 0;
    for(int i=0;i<N;i++){
        sum=0;
        for(int p=0;p<i;p++){
            sum+=arr[p];
        }
        for(int j=N-1;j>=i;j--){
            int removeCoins = arr[j]-arr[i];
            if(removeCoins>K){
                sum=sum+removeCoins-K;
            }else
                break;
        }
        RemovedCoin = min(sum,RemovedCoin);
    }
    return RemovedCoin;
}