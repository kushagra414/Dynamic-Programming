#include <bits/stdc++.h>
using namespace std;

int solution_min(int A[],int N,int K){
    sort(A,A+N);
    int sum=0,i=0,j=N-1;
    while(i<=j){
        sum=sum+A[i];
        j=j-K;
        i++;
    }
    return sum;
}

int solution_max(int A[],int N,int K){
    sort(A,A+N,greater<int>());
    int sum=0,i=0,j=N-1;
    while(i<=j){
        sum=sum+A[i];
        j=j-K;
        i++;
    }
    return sum;
}

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
	    int min=solution_min(A,N,K);
	    int max=solution_max(A,N,K);
	    cout<<min<<" "<<max<<endl;
	}
	return 0;
}
