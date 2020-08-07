#include <bits/stdc++.h>
using namespace std;

int solution(int A[],int N,int K){
    if(N==1){
        return 0;
    }
    sort(A,A+N);
    int diff=A[N-1]-A[0];
    int small=A[0]+K;
    int big=A[N-1]-K;
    if(small>big){
        swap(small,big);
    }
    for(int i=1;i<N-1;i++){
        int add=A[i]+K;
        int sub=A[i]-K;
        if(sub>=small || add<=big){
            continue;
        }
        if(big-sub<=add-small){
            small=sub;
        }
        else{
            big=add;
        }
    }
    return min(diff,big-small);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int K,N;
	    cin>>K>>N;
	    int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    cout<<solution(A,N,K)<<endl;
	}
	return 0;
}
