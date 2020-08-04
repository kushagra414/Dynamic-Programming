#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K,minCost=0,maxCost=0;
	    cin>>N>>K;
	    int candy[N];
	    for(int i=0;i<N;i++)
	        cin>>candy[i];
	    sort(candy,candy+N);
	    int end = N;
	    for(int i=0;i<end;i++){
	        minCost+=candy[i];
	        end-=K;
	    }
	    end = 0;
	    for(int i = N-1;i>=end;i--){
	        maxCost+=candy[i];
	        end+=K;
	    }
	    cout<<minCost<<" "<<maxCost<<endl;
	}
	return 0;
}