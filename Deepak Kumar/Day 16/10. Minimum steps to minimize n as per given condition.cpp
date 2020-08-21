#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int dp[N];
	    dp[0]=0;
	    dp[1]=0;
	    dp[2]=1;
	    dp[3]=1;
	    for(int i=4;i<=N;i++){
	        if(i%2==0 && i%3==0){
	            dp[i]=min({dp[i/2],dp[i/3],dp[i-1]})+1;
	        }
	        else if(i%3==0){
	            dp[i]=min(dp[i/3],dp[i-1])+1;
	        }
	        else if(i%2==0){
	            dp[i]=min(dp[i/2],dp[i-1])+1;
	        }
	        else{
	            dp[i]=dp[i-1]+1;
	        }
	    }
	    cout<<dp[N]<<endl;
	}
	return 0;
}
