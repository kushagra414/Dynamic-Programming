class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1,majEle=nums[0];
        for(int i=1;i<nums.size();i++){
            if(majEle == nums[i])
                count++;
            else{
                count--;
                if(count==0){
                    majEle = nums[i];
                    count = 1;
                }
            }
        }
        return majEle;
    }
};