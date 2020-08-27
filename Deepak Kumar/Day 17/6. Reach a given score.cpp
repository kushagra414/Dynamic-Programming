#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N+1]={0};
	    A[0]=1;
	    for(int i=3;i<=N;i++){
	        A[i]+=A[i-3];
	    }
	    for(int i=5;i<=N;i++){
	        A[i]+=A[i-5];
	    }
	    for(int i=10;i<=N;i++){
	        A[i]+=A[i-10];
	    }
	    cout<<A[N]<<endl;
	}
	return 0;
}
