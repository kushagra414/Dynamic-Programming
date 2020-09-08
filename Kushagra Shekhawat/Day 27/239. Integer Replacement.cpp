class Solution {
public:
    int integerReplacement(uint32_t n) {
        int steps = 0;
        while(n != 1){
            if(n == 3){
                steps +=2;
                break;
            }
            else if(n & 1){
                if(((n+1)>>1 & 1)){
                    n -= 1;
                }else
                    n += 1;
            }else
                n >>= 1;
            steps++;
        }
        return steps;
    }
};