#include<bits/stdc++.h>
using namespace std;

long long int findSOS(int m,int n);

int main()
 {
    long long int dp[101];
	int T;
	cin>>T;
	while(T--){
	    int m,n;
	    cin>>m>>n;
	    cout<<findSOS(m,n)<<endl;
	}
	return 0;
}

long long int findSOS(int m,int n){
    long long int SOS[n+1][m+1] = {0};
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 or j==0)
                SOS[i][j]=0;
            else if(i>j)
                SOS[i][j]=0;
            else if(i==1)
                SOS[i][j]=j;
            else{
                SOS[i][j] = SOS[i][j-1]+SOS[i-1][j/2];
            }
        }
    }
    return SOS[n][m];
}