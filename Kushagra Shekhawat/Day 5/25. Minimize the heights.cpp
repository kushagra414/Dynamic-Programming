#include<bits/stdc++.h>
using namespace std;

int minDiff(int arr[],int N,int K);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>K>>N;
	    int arr[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	    }
	    sort(arr,arr+N);
	    cout<<minDiff(arr,N,K)<<endl;
	}
	return 0;
}

int minDiff(int arr[],int N,int K){
    if(N==1)
        return 0;
    int ans = arr[N-1]-arr[0];
    int mini = arr[0]+K;
    int maxi = arr[N-1]-K;
    if(mini>maxi)
        swap(mini,maxi);
    
    for(int i=0;i<N;i++){
        int add = arr[i]+K;
        int sub = arr[i]-K;
        if(sub>=mini or add<=maxi)
            continue;
        
        if(maxi-sub<=add-mini)
            mini =sub;
        else
            maxi = add;
    }
    return min(ans,maxi-mini);
}