#include <iostream>
using namespace std;

int solution(int N){
    int dp[N];
    dp[0]=dp[1]=dp[2]=1;
    for(int i=3;i<=N;i++){
        dp[i]=((dp[i-2]+dp[i-3])%1000000007);
    }
    return dp[N] ;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    cout<<solution(N)<<endl;
	}
	return 0;
}
