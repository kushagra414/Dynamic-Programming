class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor=0,num1=0,num2=0;
        for(auto num: nums)
            Xor ^= num;
        //Extract the right most set bit which is one.
       int rightMostBit = Xor & ~(Xor-1);
        for(auto num: nums){
            if(rightMostBit & num)
                num1 ^= num;
            else
                num2 ^= num;
        }
        return {num1,num2};
    }
};