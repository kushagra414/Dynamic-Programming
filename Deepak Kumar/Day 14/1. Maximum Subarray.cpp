class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n<=0){
            return 0;
        }
        for(int i=1;i<n;i++){
            if(nums[i-1]>0){
                nums[i]=nums[i]+nums[i-1];
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,nums[i]);
        }
        return ans;
    }
};
