#include <bits/stdc++.h>
using namespace std;

int solution(int maximum,int n){
    int dp[maximum+1][n+1];
    for(int i=0;i<=maximum;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0 || i<j){
                dp[i][j]=0;
            }
            else if(j==1){
                dp[i][j]=i;
            }
            else{
                dp[i][j]=dp[i-1][j] + dp[i/2][j-1];
            }
        }
    }
    return dp[maximum][n];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int maximum,n;
	    cin>>maximum>>n;
	    cout<<solution(maximum,n)<<endl;
	}
	return 0;
}
