#include<iostream>
using namespace std;

struct LS{
  int val,LIS=1;  
};

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,maxLS=1;
	    cin>>N;
	    LS A[N];
	    for(int i=0;i<N;i++)
	        cin>>A[i].val;
	    for(int i=1;i<N;i++){
	        for(int j=0;j<i;j++){
	            if(abs(A[i].val-A[j].val)==1){
	                A[i].LIS = max(A[j].LIS+1,A[i].LIS);
	                maxLS = max(maxLS,A[i].LIS);
	            }
	        }
	    }
	    cout<<maxLS<<endl;
	}
	return 0;
}