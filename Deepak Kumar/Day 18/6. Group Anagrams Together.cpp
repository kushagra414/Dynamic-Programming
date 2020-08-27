#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> p1,pair<string,int> p2){
    return p1.second<p2.second;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    string A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	        sort(A[i].begin(),A[i].end());
	    }
	    unordered_map<string,int> mp;
	    for(int i=0;i<N;i++){
	        mp[A[i]]++;
	    }
	    vector<pair<string,int>> v(mp.begin(),mp.end());
	    sort(v.begin(),v.end(),compare);
	    for(auto it:v){
	        cout<<it.second<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
