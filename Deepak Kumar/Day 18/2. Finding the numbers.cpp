#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int len=2*N+2;
	    int A[len];
	    for(int i=0;i<len;i++){
	        cin>>A[i];
	    }
	    map<int,int> mp;
	    for(int i=0;i<len;i++){
	        mp[A[i]]++;
	    }
	    for(auto it:mp){
	        if(it.second%2==1){
	            cout<<it.first<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
