#include <bits/stdc++.h>
using namespace std;
long long dp[1001][1001];

long long solution(long long A[],long long N,long long knapsack){
    if(knapsack>0 && N<=0){
        return INT_MAX;
    }
    if(knapsack==0 || N==0){
        return 0;
    }
    if(dp[N][knapsack]!=-1){
        return dp[N][knapsack];
    }
    if(A[N-1]!=-1 && N<=knapsack){
        return dp[N][knapsack]=min(solution(A,N-1,knapsack)
        ,min(A[N-1]+solution(A,N,knapsack-N),A[N-1]+solution(A,N-1,knapsack-N)));
    }
    else{
        return dp[N][knapsack]=solution(A,N-1,knapsack);
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    long long N,knapsack;
	    cin>>N>>knapsack;
	    long long A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    for(int i=0;i<=1000;i++){
	        for(int j=0;j<=1000;j++){
	            dp[i][j]=-1;
	        }
	    }
	    long long ans=solution(A,N,knapsack)==INT_MAX?-1:solution(A,N,knapsack);
	    cout<<ans<<endl;
	}
	return 0;
}
