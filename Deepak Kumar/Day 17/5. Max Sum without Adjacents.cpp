#include <bits/stdc++.h>
using namespace std;

int solution(int A[],int N){
    int excl=0;
    int incl=A[0];
    int excl_new;
    for(int i=1;i<N;i++){
        excl_new=max(excl,incl);
        incl=excl+A[i];
        excl=excl_new;
    }
    return max(excl,incl);
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
