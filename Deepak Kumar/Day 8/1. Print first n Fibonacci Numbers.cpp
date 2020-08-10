#include <iostream>
using namespace std;

void solution(long long int dp[],int N){
    if(N>=2){
        for(int i=2;i<=N;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
    }
    for(int i=0;i<N;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return ;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    long long int dp[N+1];
        dp[0]=dp[1]=1;
	    solution(dp,N);
	}
	return 0;
}
