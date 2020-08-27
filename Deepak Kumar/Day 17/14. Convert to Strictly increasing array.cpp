#include <bits/stdc++.h>
using namespace std;

int solution(int A[],int N){
    int dp[N];
    for(int i=0;i<N;i++){
        dp[i]=1;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[j]<A[i] && ((i-j)<=(A[i]-A[j]))){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=*max_element(dp,dp+N);
    return N-ans;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    cout<<solution(A,N)<<endl;
	}
	return 0;
}
