#include <bits/stdc++.h>
using namespace std;
int dp[101][101];

int solution(string s1,int m,string s2,int n){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int m,n;
	    cin>>m>>n;
	    string s1,s2;
	    cin>>s1>>s2;
	    memset(dp,0,sizeof(dp));
	    cout<<solution(s1,m,s2,n)<<endl;
	}
	return 0;
}
