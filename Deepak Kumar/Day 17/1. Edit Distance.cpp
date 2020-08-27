#include <bits/stdc++.h>
using namespace std;

int solution(string str1,int M,string str2,int N){
    int dp[M][N];
    for(int i=0;i<N;i++){
        dp[0][i]=i;
    }
    for(int i=0;i<M;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<M;i++){
        for(int j=1;j<N;j++){
            if(str1[i]==str2[j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(str1[i]!=str2[j]){
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }
    return dp[M-1][N-1];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int M,N;
	    cin>>M>>N;
	    string str1,str2;
	    cin>>str1>>str2;
	    str1='0'+str1;
	    str2='0'+str2;
	    cout<<solution(str1,M+1,str2,N+1)<<endl;
	}
	return 0;
}
