#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    vector<int >v;
	    for(int i=0;i<N*N;i++){
	        int temp;
	        cin>>temp;
	        v.push_back(temp);
	    }
	    sort(v.begin(),v.end());
	    vector<int> :: iterator it;
	    for(it=v.begin();it!=v.end();it++){
	        cout<<*it<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
