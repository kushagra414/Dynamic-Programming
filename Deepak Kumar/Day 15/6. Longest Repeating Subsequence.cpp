#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int solution(string s,int N){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(s[i-1]==s[j-1] && i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[N][N];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    string s;
	    cin>>s;
	    cout<<solution(s,N)<<endl;
	}
	return 0;
}
