#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>N>>K;
	    int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    unordered_map<int,int> mp;
	    for(int i=0;i<N;i++){
	        mp[A[i]]=i;
	    }
	    if(K==0){
	        continue;
	    }
	    else if(K>=N){
	        sort(A,A+N,greater<int>());
	    }
	    else{
	        for(int j=N;j>0;j--){
	            if(K>0){
	                int initial_index=mp[j];
	                int best_index=N-j;
	                if(initial_index!=best_index){
	                    mp[j]=best_index;
	                    int temp=A[best_index];
	                    mp[temp]=initial_index;
	                    swap(A[initial_index],A[best_index]);
	                    K--;
	                }
	            }
	        }
	    }
	    for(int i=0;i<N;i++){
	        cout<<A[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
