#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int dp[N];
	    memset(dp,0,sizeof(dp));
	    for(int i=1;i<=N;i++){
	        dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
	    }
	    cout<<dp[N]<<endl;
	}
	return 0;
}
