#include<iostream>
using namespace std;

int coinChange(int coins[],int totalCoins,int sum);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int totalCoins,sum;
	    cin>>totalCoins;
	    int denominations[totalCoins];
	    for(int i=0;i<totalCoins;i++)
	        cin>>denominations[i];
	    cin>>sum;
	    cout<<coinChange(denominations,totalCoins,sum)<<endl;
	}
	return 0;
}

int coinChange(int coins[],int totalCoins,int sum){
    int coinChangeDP[totalCoins+1][sum+1],previousCoins,remainingChange;
    
    for(int i=0;i<=totalCoins;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 and j==0){
                //Number of ways to make a sum of 0 using 0 coins is 1.
                coinChangeDP[i][j] = 1;
                continue;
            }else if(i==0 and j>0){
                // Number of ways to make a sum of >0 using 0 coins is 0.
                coinChangeDP[i][j] = 0;
                continue;
            }
            if(coins[i-1]>j){
                // If your coin is greater than the sum.
                coinChangeDP[i][j] = coinChangeDP[i-1][j];
            }else{
                //If we do not include the coin, what is total ways:-
                previousCoins = coinChangeDP[i-1][j];
                //If we include the coin, then the total ways:-
                remainingChange = coinChangeDP[i][j-coins[i-1]];
                coinChangeDP[i][j] = previousCoins+remainingChange;
            }
        }
    }
    return coinChangeDP[totalCoins][sum];
}