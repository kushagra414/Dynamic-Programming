#include <bits/stdc++.h>
using namespace std;

int solution(int row,int col){
    int mat[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>mat[i][j];
        }
    }
    int ans=0;
    int dp[row+1][col+1];
    for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(mat[i-1][j-1]==1){
                dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int row,col;
	    cin>>row>>col;
	    cout<<solution(row,col)<<endl;
	}
	return 0;
}
