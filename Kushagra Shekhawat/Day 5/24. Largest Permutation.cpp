#include <bits/stdc++.h> 
using namespace std; 
void KswapPermutation(int arr[], int n, int k) 
{ 
	int pos[n + 1]; 

	for (int i = 0; i < n; ++i) 
		pos[arr[i]] = i; 

	for (int i = 0; i < n && k; ++i) { 
		if (arr[i] == n - i) 
			continue; 

		int temp = pos[n - i]; 
		pos[arr[i]] = pos[n - i]; 
		pos[n - i] = i; 

		swap(arr[temp], arr[i]); 
		--k; 
	} 
} 

// Driver code 
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
    	KswapPermutation(arr, N, K);
    	for (int i = 0; i < N; ++i) 
    		cout<<arr[i]<<" ";
    	cout<<endl;
    }
	return 0; 
} 
