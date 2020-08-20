#include <bits/stdc++.h>
using namespace std;

void solution(int A[],int N){
    int dp[N];
    for(int i=0;i<N;i++){
        dp[i]=1;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<N;i++){
        ans=max(ans,dp[i]);
    }
    cout<< ans<<endl;
}

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
	    solution(A,N);
	}
	return 0;
}
