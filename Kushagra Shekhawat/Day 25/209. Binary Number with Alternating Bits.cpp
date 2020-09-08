class Solution {
public:
    bool hasAlternatingBits(int num) {
        bool isOdd,wasOdd = num & 1;
        while(num){
            num = num>>1;
            isOdd = num & 1;
            if(wasOdd == isOdd){
                //There are 2 consecutive 1s or two conecutive 0s
                return false;
            }
            wasOdd = isOdd;
        }
        return true;
    }
    
};