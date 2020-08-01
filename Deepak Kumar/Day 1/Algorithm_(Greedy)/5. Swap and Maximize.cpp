#include <bits/stdc++.h>
using namespace std;

int solution(int A[],int N){
    int i=0,j=N-1;
    sort(A,A+N);
    int sum=0;
    for(int i=0;i<N/2;i++){
        sum=sum-2*A[i];
        sum=sum+2*A[N-1-i];
    }
    return sum;
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
