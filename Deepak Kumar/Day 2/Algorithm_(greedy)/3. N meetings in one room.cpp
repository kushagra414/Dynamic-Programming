#include <bits/stdc++.h>
using namespace std;

struct Activity{
    long int start,end,index;
};

bool compare(Activity A1, Activity A2){
    return A1.end<A2.end;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    Activity A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i].start;
	        A[i].index=i+1;
	    }
	    for(int i=0;i<N;i++){
	        cin>>A[i].end;
	    }
	    sort(A,A+N,compare);
	    int i=0;
	    cout<<A[i].index<<" ";
	    for(int j=1;j<N;j++){
	        if(A[j].start>=A[i].end){
	            cout<<A[j].index<<" ";
	            i=j;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
