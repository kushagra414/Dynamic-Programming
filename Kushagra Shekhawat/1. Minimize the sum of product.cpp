#include<bits/stdc++.h>
using namespace std;

unsigned long long int findMinSum(unsigned long long int A[],unsigned long long int B[], int N);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    unsigned long long int A[N],B[N];
	    for(int i=0;i<N;i++)
	        cin>>A[i];
	    for(int i=0;i<N;i++)
	        cin>>B[i];
	    sort(A,A+N);
	    sort(B,B+N);
	    cout<<findMinSum(A,B,N)<<endl;
	}
	return 0;
}
unsigned long long int findMinSum(unsigned long long int A[],unsigned long long int B[], int N){
    unsigned long long int sum =0;
    for(int i=0,j=N-1; i<N; i++,j--){
        sum+=A[i]*B[j];
    }
    return sum;
}