#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int dp[10001];
    dp[0] = 0,dp[1] = 0,dp[2] = 1,dp[3] = 1;
    int maxFound=3;
	int T;
	cin>>T;
	while(T--){
	    int n,steps=0;
	    cin>>n;
	    for(int i=maxFound+1;i<=n;i++){
	        dp[i] = min(dp[i/2]+i%2+1,dp[i/3]+i%3+1);
	    }
	    maxFound = max(maxFound,n);
	    cout<<dp[n]<<endl;
	}
	return 0;
}