#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>N>>K;
	    long long int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    sort(A,A+N);
	    long long int temp=0,sum=0,ans=INT_MAX;
	    for(int i=0;i<N;i++){
	        temp=sum;
	        sum=sum+A[i];
	        for(int j=N-1;j>i;j--){
	            if(A[j]-A[i]-K>0){
	                temp=temp+A[j]-A[i]-K;
	            }
	        }
	        ans=min(ans,temp);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
