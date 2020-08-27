#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    long long dp[N+1];
	    dp[0]=dp[1]=dp[2]=dp[3]=1;
	    for(int i=4;i<=N;i++){
	        dp[i]=dp[i-4]+dp[i-1];
	    }
	    cout<<dp[N]<<endl;
	}
	return 0;
}
