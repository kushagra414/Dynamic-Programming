#include <bits/stdc++.h>
using namespace std;
int dp[1000001];

int solution(int N){
    dp[0]=dp[1]=dp[2]=dp[3]=0;
    dp[4]=1;
    for(int i=5;i<=N;i++){
        int num=i;
        dp[i]=dp[i-1];
        while(num){
            int temp=num%10;
            if(temp==4){
                dp[i]=dp[i-1]+1;
            }
            num=num/10;
        }
    }
    return dp[N];
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
