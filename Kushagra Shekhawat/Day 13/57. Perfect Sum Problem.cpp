#include<bits/stdc++.h>
using namespace std;

unsigned long long findSumSubsets(int arr[],int size,int K);


int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    cin>>K;
	    cout<<findSumSubsets(arr,N,K)<<endl;
	}
	return 0;
}

unsigned long long int findSumSubsets(int arr[],int size,int K){
    unsigned long long int dp[size+1][K+1];
    for(int i=0;i<=size;i++){
        for(int j=0;j<=K;j++){
            if(i==0 and j==0){
                //number of coins 0, to make sum 0
                dp[i][j]=1;
                continue;
            }else if(i==0){
                // 0 coins cannot make sum greater than 0
                dp[i][j]=0;
            }else if(arr[i-1]>j){
                //if the number is greater than sum
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = (dp[i-1][j]+dp[i-1][j-arr[i-1]])%1000000007;
            }
        }
    }
    return dp[size][K];
}