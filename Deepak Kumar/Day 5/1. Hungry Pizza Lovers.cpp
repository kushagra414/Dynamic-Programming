#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    vector<pair<int,int>> v;
	    for(int i=0;i<N;i++){
	        int x,y;
	        cin>>x>>y;
	        v.push_back(make_pair(x+y,i+1));
	        sort(v.begin(),v.end());
	    }
	    for(int i=0;i<v.size();i++){
	        cout<<v[i].second<<endl;
	    }
	}
	return 0;
}
