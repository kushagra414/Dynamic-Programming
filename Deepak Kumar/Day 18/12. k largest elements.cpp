#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>N>>K;
	    int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    sort(A,A+N,greater<int>());
	    for(int i=0;i<K;i++){
	        cout<<A[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
