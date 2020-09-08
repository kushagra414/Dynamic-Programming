class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitCount[32] = {0};
        string num;
        for(auto num: nums){
            bitset<32> bitSet(num);
            for(int i=0;i<32;i++){
                bitCount[i] += bitSet[i];
            }
        }
        for(int i=0;i<32;i++)
            num += to_string(bitCount[i]%3);
        reverse(num.begin(),num.end());
        return stoul(num,0,2);
    }
};