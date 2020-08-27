
#include<bits/stdc++.h>
using namespace std;

struct Element{
    int val,row,col;
};
struct Compare{
    bool operator()(Element e1,Element e2){
        return e1.val>e2.val;
    }
};

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n,val;
	    cin>>n;
	    Element matrix[n][n],temp;
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++){
	            cin>>val;
	            matrix[i][j].val = val;
	            matrix[i][j].row = i;
	            matrix[i][j].col = j;
	        }
	   priority_queue<Element, vector<Element>, Compare>pq;
	   for(int j=0;j<1;j++){
	        for(int i=0;i<n;i++){
	            pq.push(matrix[i][j]);
	        }
	    }
	    while(!pq.empty()){
	    	temp = pq.top();
	        pq.pop();
    	    cout<<temp.val<<" ";
    	    if(temp.col<n-1)
    	        pq.push(matrix[temp.row][temp.col+1]);
	    }
	cout<<endl;
	}
	return 0;
}