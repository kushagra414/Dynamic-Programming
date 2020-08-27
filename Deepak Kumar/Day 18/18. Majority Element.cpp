#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    map<int ,int> mp;
	    for(int i=0;i<N;i++){
	        mp[A[i]]++;
	    }
	    int ans=-1;
	    for(auto it=mp.begin();it!=mp.end();it++){
	        if((it->second)>N/2){
	            ans=it->first;
	            break;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
