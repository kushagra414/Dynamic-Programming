class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int oddNum=0;
        for(auto num:nums){
            oddNum ^= num;
        }
        return oddNum;
    }
};