#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int mat[N][N];
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            cin>>mat[i][j];
	        }
	    }
	    for(int i=1;i<N;i++){
	        for(int j=0;j<N;j++){
	            if(j==0){
	                mat[i][j]+=max(mat[i-1][j],mat[i-1][j+1]);
	            }
	            else if(j==N-1){
	                mat[i][j]+=max(mat[i-1][j],mat[i-1][j-1]);
	            }
	            else{
	                mat[i][j]+=max({mat[i-1][j],mat[i-1][j-1],mat[i-1][j+1]});
	            }
	        }
	    }
	    int ans=0;
	    for(int i=0;i<N;i++){
	        ans=max(ans,mat[N-1][i]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
