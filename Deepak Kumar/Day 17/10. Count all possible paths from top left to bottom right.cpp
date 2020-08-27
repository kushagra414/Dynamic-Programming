#include <iostream>
using namespace std;
long long int dp[101][101];

int main() {
	int T;
	cin>>T;
	while(T--){
	    int M,N;
	    cin>>M>>N;
	    for(int i=0;i<N;i++){
	        dp[0][i]=1;
	    }
	    for(int i=0;i<M;i++){
	        dp[i][0]=1;
	    }
	    for(int i=1;i<=M;i++){
	        for(int j=1;j<=N;j++){
	            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
	        }
	    }
	    cout<<dp[M-1][N-1]<<endl;
	}
	return 0;
}
