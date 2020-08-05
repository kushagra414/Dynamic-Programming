#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K,totalToys=0;
	    cin>>N>>K;
	    int toys[N];
	    for(int i=0;i<N;i++){
	        cin>>toys[i];
	    }
	    sort(toys,toys+N);
	    for(int i=0;i<N;i++){
	        if(toys[i]<=K){
	            totalToys++;
	            K-=toys[i];
	        }
	    }
	    cout<<totalToys<<endl;
	}
	return 0;
}