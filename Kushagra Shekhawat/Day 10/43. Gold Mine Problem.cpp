#include<bits/stdc++.h>
using namespace std;

int FindMaxGold(vector<vector<int>>&GoldMine,int rows,int cols);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,M,x;
	    cin>>N>>M;
	    vector<vector<int>>GoldMine(N);
	    for(int i=0;i<N;i++){
	        GoldMine[i] = vector<int>(M);
	        for(int j=0;j<M;j++){
	            cin>>x;
	            GoldMine[i][j] = x;
	        }
	    }
	    cout<<FindMaxGold(GoldMine,N,M)<<endl;
	}
	return 0;
}

int FindMaxGold(vector<vector<int>>&GoldMine,int rows,int cols){
    int row,maxGoldCollected=GoldMine[0][0];
    for(int j=0;j<cols;j++)
        for(int i=0;i<rows;i++){
            if(j>0 and (i==0 or i==rows-1)){
                if(i+1==rows and rows>1)
                    row = i-1;
                else if(rows>1)
                    row = i+1;
                else
                    row = i;
                GoldMine[i][j]+=max(GoldMine[i][j-1],
                GoldMine[row][j-1]);
            }else if(j>0 and i>0){
                GoldMine[i][j]+=max(GoldMine[i][j-1],
                max(GoldMine[i-1][j-1],GoldMine[i+1][j-1]));
            }
            maxGoldCollected = max(GoldMine[i][j],
            maxGoldCollected);
        }
    return maxGoldCollected;
}