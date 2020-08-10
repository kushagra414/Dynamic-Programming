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
	    int k,page_fault=0;
	    cin>>k;
	    int j=0;
	    vector<int> v;
	    vector<int> :: iterator it;
	    for(int i=0;i<N;i++){
	        if(find(v.begin(),v.end(),A[i])!=v.end()){
	            it=find(v.begin(),v.end(),A[i]);
	            v.erase(it);
	            v.push_back(A[i]);
	        }
	        else if(find(v.begin(),v.end(),A[i])==v.end() && j<k){
	            v.push_back(A[i]);
	            page_fault++;
	            j++;
	        }
	        else{
	            v.erase(v.begin());
	            page_fault++;
	            v.push_back(A[i]);
	        }
	    }
	    cout<<page_fault<<endl;
	}
	return 0;
}
