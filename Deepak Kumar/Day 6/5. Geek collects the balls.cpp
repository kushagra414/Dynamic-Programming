#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int M,N;
	    cin>>M>>N;
	    int A[M],B[N];
	    for(int i=0;i<M;i++){
	        cin>>A[i];
	    }
	    for(int i=0;i<N;i++){
	        cin>>B[i];
	    }
	    int sum1=0,sum2=0,sum=0;
	    int i=0,j=0;
	    while(i<M && j<N){
	        if(A[i]<B[j]){
	            sum1=sum1+A[i];
	            i++;
	        }
	        else if(A[i]>B[j]){
	            sum2=sum2+B[j];
	            j++;
	        }
	        else{
	            int a=A[i];
	            while(A[i]==a && i<M){
	                sum1=sum1+A[i];
	                i++;
	            }
	            while(B[j]==a &&j<N){
	                sum2=sum2+B[j];
	                j++;
	            }
	            sum=sum+max(sum1,sum2);
	            sum1=0;
	            sum2=0;
	        }
	    }
	    while(i<M){
	        sum1=sum1+A[i];
	        i++;
	    }
	    while(j<N){
	        sum2=sum2+B[j];
	        j++;
	    }
	    sum=sum+max(sum1,sum2);
	    cout<<sum<<endl;
	}
	return 0;
}
