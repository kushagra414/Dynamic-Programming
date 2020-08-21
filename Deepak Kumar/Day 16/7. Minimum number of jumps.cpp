#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10000001];

ll solution(ll A[],ll N){
    if(A[0]==0 || N==0){
        return -1;
    }
    ll dp[N];
    for(ll i=0;i<N;i++){
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(ll i=1;i<N;i++){
        for(ll j=0;j<i;j++){
            if(i<=j+A[j]){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[N-1]==INT_MAX?-1:dp[N-1];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    ll N;
	    cin>>N;
	    ll A[N];
	    for(ll i=0;i<N;i++){
	        cin>>A[i];
	    }
	    cout<<solution(A,N)<<endl;
	}
	return 0;
}
