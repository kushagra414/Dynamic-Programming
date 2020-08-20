#include <bits/stdc++.h>
using namespace std;
long long dp[100001];

int solution(int fence,int paint){
    dp[1]=paint;
    dp[2]=paint*(paint-1)+paint;
    for(int i=3;i<=fence;i++){
        dp[i]=((dp[i-1]+dp[i-2])*(paint-1))%(long long)(1e9 + 7);
    }
    return dp[fence];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int fence,paint;
	    cin>>fence>>paint;
	    memset(dp,0,sizeof(dp));
	    cout<<solution(fence,paint)<<endl;
	}
	return 0;
}
