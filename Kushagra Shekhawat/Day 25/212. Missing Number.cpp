class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XorWhenNoneMissing=0,trueXor=0,i;
        for(i=0;i<nums.size();i++){
            XorWhenNoneMissing ^= i;
            trueXor ^= nums[i];
        }
        XorWhenNoneMissing ^= i;
        return XorWhenNoneMissing ^ trueXor;
        //This will give the changed bits
    }
};