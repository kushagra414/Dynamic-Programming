#include <bits/stdc++.h>
using namespace std;
int dp[51];

int left(int A[],int start,int end,int maximum){
    if(start>end){
        return 0;
    }
    else if(A[end]>=maximum){
        return left(A,start,end-1,maximum);
    }
    else{
        return max(A[end]+left(A,start,end-1,A[end]),left(A,start,end-1,maximum));
    }
}

int right(int A[],int start,int end,int maximum){
    if(start>end){
        return 0;
    }
    else if(A[start]>=maximum){
        return right(A,start+1,end,maximum);
    }
    else{
        return max(A[start]+right(A,start+1,end,A[start]),right(A,start+1,end,maximum));
    }
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
	    int sum=0;
	    for(int i=0;i<N;i++){
	        sum=max(sum,A[i]+left(A,0,i-1,A[i])+right(A,i+1,N-1,A[i]));
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
