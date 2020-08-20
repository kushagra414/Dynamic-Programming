class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp;
        dp.push_back(0);
        for(int i=1;i<=num;i++){
            int temp=i/2;
            if(i%2==0){
                dp.push_back(dp[temp]);
            }
            else{
                dp.push_back(dp[temp]+1);
            }
        }
        return dp;
    }
};
