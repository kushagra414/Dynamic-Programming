#include <bits/stdc++.h>
using namespace std;

int solution(int dp[],int A[],int N){
    if(N<=0){
        return 0;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                dp[i]=max(dp[i],A[i]+dp[j]);
            }
        }
    }
    int maximum=INT_MIN;
    for(int i=0;i<N;i++){
        maximum=max(maximum,dp[i]);
    }
    return maximum;
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
	        dp[i]=A[i];
	    }
	    cout<<solution(dp,A,N)<<endl;
	}
	return 0;
}
