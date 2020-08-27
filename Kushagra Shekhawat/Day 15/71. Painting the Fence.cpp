#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    long long mod = pow(10,9)+7;
	    cin>>N>>K;
	    long long int dp[N+1]={0};
	    dp[1] = K,dp[2] = K*K;
	    for(int i=3;i<=N;i++)
	        dp[i] = (long long)((K-1)*(dp[i-1]+dp[i-2])%mod);
	
	    cout<<dp[N]<<endl;
	}
	return 0;
}