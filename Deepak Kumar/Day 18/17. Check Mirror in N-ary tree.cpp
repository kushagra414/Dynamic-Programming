#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int i,int j){
    adj[i].push_back(j);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int node,edge;
	    cin>>node>>edge;
	    int len=2*edge;
	    int A[len];
	    int B[len];
	    for(int i=0;i<len;i++){
	        cin>>A[i];
	    }
	    for(int i=0;i<len;i++){
	        cin>>B[i];
	    }
	    vector<int> adjA[node];
	    vector<int> adjB[node];
	    for(int i=0;i<len;i=i+2){
	        add_edge(adjA,A[i],A[i+1]);
	    }
	    for(int i=0;i<len;i=i+2){
	        add_edge(adjB,B[i],B[i+1]);
	    }
	    for(int i=0;i<node;i++){
	        reverse(adjB[i].begin(),adjB[i].end());
	    }
	    bool flag=true;
	    for(int i=0;i<node;i++){
	        if(adjA[i]!=adjB[i]){
	            flag=false;
	            break;
	        }
	    }
	    if(flag==true){
	        cout<<"1 "<<endl;
	    }
	    else{
	        cout<<"0 "<<endl;
	    }
	}
	return 0;
}
