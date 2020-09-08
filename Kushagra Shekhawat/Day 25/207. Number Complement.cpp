class Solution {
public:
    int findComplement(int num) {
        int size = sizeof(int)*8 - __builtin_clz(num);
        if(size>30)
            return ~(INT_MIN) ^ num;
        num = num ^ (1<<size)-1;
        return num;
    }
};