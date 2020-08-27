#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N][N];
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            cin>>A[i][j];
	        }
	    }
	    map<int ,vector<int>> mp;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            mp[i+j].push_back(A[i][j]);
	        }
	    }
	    for(auto it=mp.begin();it!=mp.end();it++){
	        for(auto p=it->second.begin();p!=it->second.end();p++){
	            cout<<*p<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
