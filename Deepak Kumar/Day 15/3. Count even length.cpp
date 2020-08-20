#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];

long long solution(long long N,long long diff){
    if(abs(diff)>N){
        return 0;
    }
    else if(N==1 && diff==0){
        return 2;
    }
    else if(N==1 && abs(diff)==1){
        return 1;
    }
    else if(dp[N][N+diff]!=-1){
        return dp[N][N+diff];
    }
    else{
        return dp[N][N+diff]=(long long)((solution(N-1,diff-1)+solution(N-1,diff+1)+2*solution(N-1,diff))%1000000007);
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    memset(dp,-1,sizeof(dp));
	    cout<<solution(N,0)<<endl;
	}
	return 0;
}
