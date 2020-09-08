class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int loop  = 32;
        string reverseNum;
        while(loop--){
            reverseNum += to_string(n & 1);
            n = n>>1;
        }
        n = stoul(reverseNum,0,2);
        return n;
    }

};