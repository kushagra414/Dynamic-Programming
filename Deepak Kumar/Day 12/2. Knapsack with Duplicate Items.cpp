#include <bits/stdc++.h>
using namespace std;

int solution(int value[],int weight[],int no_of_item,int knapsack){
    int dp[no_of_item+1][knapsack+1];
    for(int i=0;i<=no_of_item;i++){
        for(int j=0;j<=knapsack;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(weight[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(value[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[no_of_item][knapsack];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int no_of_item,knapsack;
	    cin>>no_of_item>>knapsack;
	    int value[no_of_item];
	    int weight[no_of_item];
	    for(int i=0;i<no_of_item;i++){
	        cin>>value[i];
	    }
	    for(int i=0;i<no_of_item;i++){
	        cin>>weight[i];
	    }
	    cout<<solution(value,weight,no_of_item,knapsack)<<endl;
	}
	return 0;
}
