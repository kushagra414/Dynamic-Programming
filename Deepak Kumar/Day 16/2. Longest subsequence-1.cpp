#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    int dp[N];
	    for(int i=0;i<N;i++){
	        dp[i]=1;
	    }
	    for(int i=1;i<N;i++){
	        for(int j=0;j<i;j++){
	            if(abs(A[i]-A[j])==1){
	                dp[i]=max(dp[i],dp[j]+1);
	            }
	        }
	    }
	    int ans =INT_MIN;
	    for(int i=0;i<N;i++){
	        ans=max(ans,dp[i]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
