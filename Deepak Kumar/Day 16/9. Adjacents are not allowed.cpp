#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int mat[2][N];
	    for(int i=0;i<2;i++){
	        for(int j=0;j<N;j++){
	            cin>>mat[i][j];
	        }
	    }
	    int dp[N];
	    for(int i=0;i<N;i++){
	        dp[i]=max(mat[0][i],mat[1][i]);
	    }
	    int ans[N];
	    ans[0]=dp[0];
	    ans[1]=max(dp[0],dp[1]);
	    for(int i=2;i<N;i++){
	        ans[i]=max(ans[i-1],dp[i]+ans[i-2]);
	    }
	    cout<<ans[N-1]<<endl;
	}
	return 0;
}
