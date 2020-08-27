#include <bits/stdc++.h>
using namespace std;

int main() {
	long long T;
	cin>>T;
	while(T--){
	    long long N;
	    cin>>N;
	    long long A[N],sum=0,prod=1;
	    for(long long i=0;i<N;i++){
	        cin>>A[i];
	    }
	    long long repeating_no,missing_no;
	    unordered_map<long long,long long>mp;
	    for(int i=0;i<N;i++){
	        mp[A[i]]++;
	    }
	    for(int i=0;i<N;i++){
	        if(mp.find(i+1)==mp.end()){
	            missing_no=i+1;
	            break;
	        }
	    }
	    for(auto it:mp){
	        if(it.second==2){
	            repeating_no=it.first;
	            break;
	        }
	    }
	    cout<<repeating_no<<" "<<missing_no<<endl;
	}
	return 0;
}
