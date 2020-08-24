#include<bits/stdc++.h>
using namespace std;

int findMinCost(int oranges[],int n,int knapSack);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n,knapSack;
	    cin>>n>>knapSack;
	    int oranges[n];
	    for(int i=0;i<n;i++)
	        cin>>oranges[i];
	    cout<<findMinCost(oranges,n,knapSack)<<endl;
	}
	return 0;
}

int findMinCost(int oranges[],int n,int knapSack){
    int minCost[n+1][knapSack+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<knapSack+1;j++){
            if((i==0 and j==0) or j==0){
                minCost[i][j] = 0;
            }else if(i==0 and j!=0){
                minCost[i][j] = INT_MAX;
            }else if(oranges[i-1]==-1 or i>j){
                minCost[i][j] = minCost[i-1][j];
            }else{
                if(minCost[i][j-i]==INT_MAX)
                    minCost[i][j] = INT_MAX;
                else
                    minCost[i][j] = min(oranges[i-1]+minCost[i][j-i],
                                                     minCost[i-1][j]);
            }
        }
    }
    if(minCost[n][knapSack]==INT_MAX)
        return -1;
    else return minCost[n][knapSack];
}