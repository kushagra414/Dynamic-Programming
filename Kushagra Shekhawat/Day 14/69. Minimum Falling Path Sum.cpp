class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& dp) {
        int n = dp.size();
        if(n==1)
            return dp[0][0];
        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                if(col==0)
                    dp[row][col] += min(dp[row-1][col],
                                        dp[row-1][col+1]);
                else if(col<n-1){
                    dp[row][col] += min(dp[row-1][col-1],
                                        min(dp[row-1][col],
                                           dp[row-1][col+1]));
                }else{
                    dp[row][col] += min(dp[row-1][col-1],
                                        dp[row-1][col]);
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};