#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,M,maxSquare=0;
	    cin>>N>>M;
	    N++,M++;
	    int matrix[N][M];
	    memset(matrix,0,sizeof(matrix));
	    for(int i=1;i<N;i++)
	        for(int j=1;j<M;j++){
	            cin>>matrix[i][j];
	        }
	    for(int i=1;i<N;i++){
	        for(int j=1;j<M;j++){
	            if(matrix[i][j]==1){
	            matrix[i][j] = min(matrix[i-1][j-1],min(matrix[i-1][j],
	                                                    matrix[i][j-1]))+
	                                                    matrix[i][j];
	            maxSquare = max(maxSquare,matrix[i][j]);
	            }                                       
	        }
	    }
	    cout<<maxSquare<<endl;
	}
	return 0;
}