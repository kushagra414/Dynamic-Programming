#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int solution(const string& str,int i,int j){
    if(i>j){
        return 0;
    }
    if(i==j){
        return 1;
    }
    if(dp[i][j]){
        return dp[i][j];
    }
    if(str[i]==str[j]){
        return dp[i][j]=2+solution(str,i+1,j-1);
    }
    else{
        return dp[i][j]=max(solution(str,i,j-1),solution(str,i+1,j));
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;
	    cin>>str;
	    int n=str.length();
	    memset(dp,0,sizeof(dp));
	    cout<<solution(str,0,n)<<endl;
	}
	return 0;
}
