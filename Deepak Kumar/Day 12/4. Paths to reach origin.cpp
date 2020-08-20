#include <bits/stdc++.h>
using namespace std;
int dp[26][26];

int solution(int no_of_row,int no_of_column){
    if(no_of_row<0 || no_of_column<0){
        return 0;
    }
    else if(no_of_row==0 || no_of_column==0){
        return 1;
    }
    else if(dp[no_of_row][no_of_column]!=-1){
        return dp[no_of_row][no_of_column];
    }
    else{
        return dp[no_of_row][no_of_column]=solution(no_of_row-1,no_of_column)+solution(no_of_row,no_of_column-1);
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int no_of_row,no_of_column;
	    cin>>no_of_row>>no_of_column;
	    dp[no_of_row][no_of_column];
	    memset(dp,-1,sizeof(dp));
	    cout<<solution(no_of_row,no_of_column)<<endl;
	}
	return 0;
}
