#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N=0,K=0;
	    cin>>N>>K;
	    int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    int i=0;
	    sort(A,A+N);
	    int sum=0;
	    for(i=0;i<N;i++){
	        sum=sum+A[i];
	        if(sum>K){
	            break;
	        }
	    }
	    cout<<i<<endl;
	}
	return 0;
}
