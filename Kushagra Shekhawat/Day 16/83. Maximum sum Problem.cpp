#include<bits/stdc++.h>
using namespace std;

int maxSum(long long int n,long long int maxSumDp[],long long int &maxFound);

int main()
 {
    long long int MaxSumDp[100001];
    long long int maxFound=4;
    MaxSumDp[0] = 0;
    MaxSumDp[1] = 1,MaxSumDp[2] = 2,MaxSumDp[3] = 3,MaxSumDp[4] = 4;
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    
	    cout<<maxSum(n,MaxSumDp,maxFound)<<endl;
	}
	return 0;
}

int maxSum(long long int n,long long int dp[],long long int &maxFound){
    for(long long int i=maxFound+1;i<=n;i++){
        dp[i] = max(i,dp[i/2]+dp[i/3]+dp[i/4]);
        //cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
    }
    maxFound = max(maxFound,n);
    return dp[n];
}