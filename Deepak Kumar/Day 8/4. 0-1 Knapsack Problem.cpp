#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int solution(int value[],int weight[],int knapsack,int no_of_item){
    if(knapsack==0 || no_of_item==0){
        return 0;
    }
    else if(dp[no_of_item][knapsack]!=-1){
        return dp[no_of_item][knapsack];
    }
    else if(weight[no_of_item-1]<=knapsack){
        return dp[no_of_item][knapsack]=max(value[no_of_item-1]+solution(value,weight,knapsack-weight[no_of_item-1],no_of_item-1)
        ,solution(value,weight,knapsack,no_of_item-1));
    }
    else if(weight[no_of_item-1]>knapsack){
        return dp[no_of_item][knapsack]=solution(value,weight,knapsack,no_of_item-1);
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int no_of_item,knapsack;
	    cin>>no_of_item>>knapsack;
    	int value[no_of_item],weight[no_of_item];
    	for(int i=0;i<no_of_item;i++){
    	    cin>>value[i];
    	}
    	for(int i=0;i<no_of_item;i++){
    	    cin>>weight[i];
    	}
    	memset(dp,-1,sizeof(dp));
    	cout<<solution(value,weight,knapsack,no_of_item)<<endl;
	}
	return 0;
}
