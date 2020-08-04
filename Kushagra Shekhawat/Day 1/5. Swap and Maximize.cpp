#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N],newArray[N],k=0,sum=0;
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    sort(A,A+N);
	    int totalElements = 0;
	    for(int i=0,j=N-1;i<N;i++,j--){
	        if(totalElements<=N){
	            newArray[k++] = A[j];
                totalElements++;
                if(totalElements<=N){
                    newArray[k++] = A[i];
                    totalElements++;
                }
	        }
	    }
	    for(int i=0;i<N-1;i++){
	        sum += abs(newArray[i]-newArray[i+1]);
	    }
	    sum+=abs(newArray[N-1]-newArray[0]);
	    cout<<sum<<endl;
	}
	return 0;
}