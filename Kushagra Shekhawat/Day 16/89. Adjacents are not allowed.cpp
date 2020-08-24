#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
        int n,maxSum=0;
        cin>>n;
	    int matrix[2][n];
	    for(int i=0;i<2;i++)
	       for(int j=0;j<n;j++)
	           cin>>matrix[i][j];
	   
	   
	   int dp[n+1];
	   dp[0] = 0;
	   dp[1] = max(matrix[0][0],matrix[1][0]);
	    for(int i=2;i<=n;i++){
	        dp[i] = max(max(matrix[0][i-1],matrix[1][i-1])+dp[i-2],dp[i-1]);
	    }
	   cout<<dp[n]<<endl;
	}
	return 0;
}