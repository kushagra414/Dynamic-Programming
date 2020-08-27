#include <bits/stdc++.h>
using namespace std;

int solution(string str1,int M,string str2,int N){
    int dp[M+1][N+1];
    int ans=INT_MIN;
    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=0;
            }
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int M,N;
	    cin>>M>>N;
	    string str1,str2;
	    cin>>str1>>str2;
	    cout<<solution(str1,M,str2,N)<<endl;
	}
	return 0;
}
