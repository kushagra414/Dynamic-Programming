#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n,totalDiagonals;
	    cin>>n;
	    int matrix[n][n];
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            cin>>matrix[i][j];
	    
	    totalDiagonals = n*2-1;
	    int UD = (totalDiagonals/2)+1,LD = totalDiagonals/2;
	    for(int d=0;d<UD;d++){
	        for(int j=d,i=0;j>=0 and i<=d;j--,i++)
	                cout<<matrix[i][j]<<" ";
	    }
	    for(int d=LD;d>0;d--){
	        for(int j=n-1,i=UD-d;i<UD;j--,i++)
	                cout<<matrix[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}