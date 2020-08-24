#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K,sum=0;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    cin>>K;
	    sort(arr,arr+N);
	    for(int i=N-1,j=N-2;i>=0 and j>=0;){
	        if(abs(arr[i]-arr[j])<K){
	            sum+=arr[i]+arr[j];
	            i-=2,j-=2;
	        }else{
	            i--,j--;
	        }
	    }
	    cout<<sum<<endl;
	}
	return 0;
}