#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    unsigned long long int dp[n+1];
	    dp[0]=0;
	    dp[1]=1;
	    dp[2]=2;
	    for(int i=3;i<=n;i++){
	        dp[i]=0;
	    }
	    for(int i=3;i<=n;i++){
	        dp[i]=(dp[i-1]+((i-1)*dp[i-2]))%1000000007;
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}
