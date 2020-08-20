#include <bits/stdc++.h>
using namespace std;

void solution(long long int A[],long long int B[],long long int m,long long int n){
    long long int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=i;j<=m;j++){
            dp[i][j]=(max(dp[i-1][j-1]+(A[j-1]*B[i-1]),dp[i][j-1]));
        }
    }
    cout<<dp[n][m]<<endl;
    return;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int m,n;
	    cin>>m>>n;
	    long long int A[m],B[n];
	    for(int i=0;i<m;i++){
	        cin>>A[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>B[i];
	    }
	    solution(A,B,m,n);
	}
	return 0;
}
