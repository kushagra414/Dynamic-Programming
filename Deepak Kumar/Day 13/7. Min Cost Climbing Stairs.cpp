class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        if(len==0){
            return 0;
        }
        if(len==1){
            return cost[0];
        }
        if(len==2){
            return min(cost[1],cost[0]);
        }
        int dp[len];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<len;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[len-1],dp[len-2]);
    }
};
