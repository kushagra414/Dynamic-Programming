#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,num;
	    cin>>N>>num;
	    int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    ll dp[num+1];
	    memset(dp,0,sizeof(dp));
	    dp[0]=1;
	    for(int i=1;i<=num;i++){
	        for(int j=0;j<N;j++){
	            if(i>=A[j]){
	                dp[i] = (dp[i]+dp[i-A[j]])%(ll)(1e9+7);
	            }
	        }
	    }
	    cout<<dp[num]<<endl;
	}
	return 0;
}
