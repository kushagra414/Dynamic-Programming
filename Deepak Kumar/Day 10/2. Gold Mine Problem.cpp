#include <bits/stdc++.h>
using namespace std;

void solution(){
    int row,column;
    cin>>row>>column;
    int dp[row][column];
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>dp[i][j];
        }
	}
    int ans=0;
    if(row==0||column ==0){
        cout<<"0 ";
        return ;
    }
    else if(row==1){
        for(int i=0;i<column;i++){
            ans+=dp[0][i];
        }
        cout<<ans<<" ";
        return ;
    }
    else if(column==1){
        ans=INT_MIN;
        for(int i=0;i<row;i++){
            ans=max(ans,dp[i][0]);
        }
        cout<<ans<<" ";
        return ;
    }
    for(int i=column-2;i>=0;i--){
        for(int j=0;j<row;j++){
            if(j==0){
                dp[j][i]=dp[j][i]+max(dp[j][i+1],dp[j+1][i+1]);
            }
            else if(j==row-1){
                dp[j][i]=dp[j][i]+max(dp[j][i+1],dp[j-1][i+1]);
            }
            else{
                dp[j][i]=dp[j][i]+max(dp[j][i+1],max(dp[j-1][i+1],dp[j+1][i+1]));
            }
        }
    }
    ans=INT_MIN;
    for(int i=0;i<row;i++){
        ans=max(ans,dp[i][0]);
    }
    cout<<ans<<" ";
    return ;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    solution();
	    cout<<endl;
	}
	return 0;
}
