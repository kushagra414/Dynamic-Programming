#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int solution(int A[],int N,int K){
    if(N<=1){
        return 0;
    }
    if(dp[N][N+K]!=-1){
        return dp[N][N+K];
    }
    if(A[N-1]-A[N-2]<K){
        return dp[N][N+K]=max(A[N-1]+A[N-2]+solution(A,N-2,K),solution(A,N-1,K));
    }
    else{
        return dp[N][N+K]=solution(A,N-1,K);
    }
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
	    int K;
	    cin>>K;
	    sort(A,A+N);
	    memset(dp,-1,sizeof(dp));
	    cout<<solution(A,N,K)<<endl;
	}
	return 0;
}
