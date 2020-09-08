class Solution {
public:
    int getSum(int a, int b) {
        int sum=0;
        while(b != 0){
            sum = (a ^ b);
            // here the 0xffffffff is 2^32 -1 which will convert
            //negative carry to positive when shift becomes 32
            b = (((a & b)&0xffffffff)<<1);
            a = sum;
        }
        return sum;
    }
};