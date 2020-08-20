class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        int dp[n+1][m+1],sum=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //min of above cell, left cell and diagonal cell
                if(matrix[i-1][j-1]==1){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],
                                                    dp[i][j-1]))
                    +matrix[i-1][j-1];
                    sum+=dp[i][j];
                }
            }
        }
        return sum;
    }
};