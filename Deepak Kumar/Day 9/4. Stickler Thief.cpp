#include <bits/stdc++.h>
using namespace std;
int dp[10001];

int solution(int A[],int N){
    if(N<=0){
        return 0;
    }
    dp[0]=A[0];
    dp[1]=max(A[0],A[1]);
    for(int i=2;i<N;i++){
        dp[i]=max(dp[i-1],A[i]+dp[i-2]);
    }
    return dp[N-1];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N];
	    int dp[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    memset(dp,-1,sizeof(dp));
	    cout<<solution(A,N)<<endl;
	}
	return 0;
}
